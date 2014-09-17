
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_JSplitPane$AccessibleJSplitPane__
#define __javax_swing_JSplitPane$AccessibleJSplitPane__

#pragma interface

#include <javax/swing/JComponent$AccessibleJComponent.h>
extern "Java"
{
  namespace javax
  {
    namespace accessibility
    {
        class AccessibleRole;
        class AccessibleStateSet;
        class AccessibleValue;
    }
    namespace swing
    {
        class JSplitPane;
        class JSplitPane$AccessibleJSplitPane;
    }
  }
}

class javax::swing::JSplitPane$AccessibleJSplitPane : public ::javax::swing::JComponent$AccessibleJComponent
{

public: // actually protected
  JSplitPane$AccessibleJSplitPane(::javax::swing::JSplitPane *);
public:
  virtual ::javax::accessibility::AccessibleStateSet * getAccessibleStateSet();
  virtual ::javax::accessibility::AccessibleRole * getAccessibleRole();
  virtual ::javax::accessibility::AccessibleValue * getAccessibleValue();
  virtual ::java::lang::Number * getCurrentAccessibleValue();
  virtual jboolean setCurrentAccessibleValue(::java::lang::Number *);
  virtual ::java::lang::Number * getMinimumAccessibleValue();
  virtual ::java::lang::Number * getMaximumAccessibleValue();
private:
  static const jlong serialVersionUID = -1788116871416305366LL;
public: // actually package-private
  ::javax::swing::JSplitPane * __attribute__((aligned(__alignof__( ::javax::swing::JComponent$AccessibleJComponent)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_JSplitPane$AccessibleJSplitPane__
