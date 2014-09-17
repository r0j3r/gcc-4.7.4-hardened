/* Mode switching cleanup pass for the EPIPHANY cpu.
   Copyright (C) 2000, 2011 Free Software Foundation, Inc.
   Contributed by Embecosm on behalf of Adapteva, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "machmode.h"
#include "tm.h"
#include "hard-reg-set.h"
#include "tm_p.h"
#include "vec.h"
#include "sbitmap.h"
#include "basic-block.h"
#include "df.h"
#include "rtl.h"
#include "insn-config.h"
#include "insn-codes.h"
#include "emit-rtl.h"
#include "recog.h"
#include "function.h"
#include "insn-attr-common.h"
#include "tree-pass.h"

/* Clean-up after mode switching:
   Check for mode setting insns that have FP_MODE_ROUND_UNKNOWN.
   If only one rounding mode is required, select that one.
   Else we have to choose one to use in this mode setting insn and
   insert new mode setting insns on the edges where the other mode
   becomes unambigous.  */

static bool
gate_resolve_sw_modes (void)
{
  return optimize;
}

static unsigned
resolve_sw_modes (void)
{
  basic_block bb;
  rtx insn, src;
  VEC (basic_block, heap) *todo;
  sbitmap pushed;
  bool need_commit = false;
  bool finalize_fp_sets = (MACHINE_FUNCTION (cfun)->unknown_mode_sets == 0);

  todo = VEC_alloc (basic_block, heap, last_basic_block);
  pushed = sbitmap_alloc (last_basic_block);
  sbitmap_zero (pushed);
  if (!finalize_fp_sets)
    {
      df_note_add_problem ();
      df_analyze ();
    }
  FOR_EACH_BB (bb)
    FOR_BB_INSNS (bb, insn)
      {
	enum attr_fp_mode selected_mode;

	if (!NONJUMP_INSN_P (insn)
	    || recog_memoized (insn) != CODE_FOR_set_fp_mode)
	  continue;
	src = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
	if (finalize_fp_sets)
	  {
	    SET_SRC (XVECEXP (PATTERN (insn), 0, 2)) = copy_rtx (src);
	    if (REG_P (src))
	      df_insn_rescan (insn);
	    continue;
	  }
	if (REG_P (src)
	    || XINT (XVECEXP (XEXP (src, 0), 0, 0), 0) != FP_MODE_ROUND_UNKNOWN)
	  continue;
	if (find_regno_note (insn, REG_UNUSED, FP_TRUNCATE_REGNUM))
	  selected_mode = FP_MODE_ROUND_NEAREST;
	else if (find_regno_note (insn, REG_UNUSED, FP_NEAREST_REGNUM))
	  selected_mode = FP_MODE_ROUND_TRUNC;
	else
	  {
	    /* We could get more fancy in the selection of the mode by
	       checking the total frequency of the affected edges.  */
	    selected_mode = (enum attr_fp_mode) epiphany_normal_fp_rounding;

	    VEC_quick_push (basic_block, todo, bb);
	    SET_BIT (pushed, bb->index);
	  }
	XVECEXP (XEXP (src, 0), 0, 0) = GEN_INT (selected_mode);
	SET_SRC (XVECEXP (PATTERN (insn), 0, 1)) = copy_rtx (src);
	SET_SRC (XVECEXP (PATTERN (insn), 0, 2)) = copy_rtx (src);
	df_insn_rescan (insn);
      }
  while (VEC_length (basic_block, todo))
    {
      basic_block bb = VEC_pop (basic_block, todo);
      int selected_reg, jilted_reg;
      enum attr_fp_mode jilted_mode;
      edge e;
      edge_iterator ei;

      SET_BIT (pushed, bb->index);
      SET_BIT (pushed, bb->index);

      if (epiphany_normal_fp_rounding == FP_MODE_ROUND_NEAREST)
	{
	  selected_reg = FP_NEAREST_REGNUM;
	  jilted_reg = FP_TRUNCATE_REGNUM;
	  jilted_mode = FP_MODE_ROUND_TRUNC;
	}
      else
	{
	  selected_reg = FP_TRUNCATE_REGNUM;
	  jilted_reg = FP_NEAREST_REGNUM;
	  jilted_mode = FP_MODE_ROUND_NEAREST;
	}

      FOR_EACH_EDGE (e, ei, bb->succs)
	{
	  basic_block succ = e->dest;
	  rtx seq;

	  if (!REGNO_REG_SET_P (DF_LIVE_IN (succ), jilted_reg))
	    continue;
	  if (REGNO_REG_SET_P (DF_LIVE_IN (succ), selected_reg))
	    {
	      if (TEST_BIT (pushed, succ->index))
		continue;
	      VEC_quick_push (basic_block, todo, succ);
	      SET_BIT (pushed, bb->index);
	      continue;
	    }
	  start_sequence ();
	  emit_set_fp_mode (EPIPHANY_MSW_ENTITY_ROUND_UNKNOWN,
			    jilted_mode, NULL);
	  seq = get_insns ();
	  end_sequence ();
	  need_commit = true;
	  insert_insn_on_edge (seq, e);
	}
    }
  VEC_free (basic_block, heap, todo);
  sbitmap_free (pushed);
  if (need_commit)
    commit_edge_insertions ();
  return 0;
}

struct rtl_opt_pass pass_resolve_sw_modes =
{
 {
  RTL_PASS,
  "resolve_sw_modes",			/* name */
  gate_resolve_sw_modes,		/* gate */
  resolve_sw_modes,			/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_MODE_SWITCH,			/* tv_id */
  0,					/* properties_required */
  0,					/* properties_provided */
  0,					/* properties_destroyed */
  0,					/* todo_flags_start */
  TODO_df_finish | TODO_verify_rtl_sharing |
  0					/* todo_flags_finish */
 }
};
