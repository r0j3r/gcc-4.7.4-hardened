
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_AsyncBoxView$FlushTask__
#define __javax_swing_text_AsyncBoxView$FlushTask__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace text
      {
          class AsyncBoxView;
          class AsyncBoxView$FlushTask;
      }
    }
  }
}

class javax::swing::text::AsyncBoxView$FlushTask : public ::java::lang::Object
{

  AsyncBoxView$FlushTask(::javax::swing::text::AsyncBoxView *);
public:
  virtual void run();
public: // actually package-private
  AsyncBoxView$FlushTask(::javax::swing::text::AsyncBoxView *, ::javax::swing::text::AsyncBoxView$FlushTask *);
  ::javax::swing::text::AsyncBoxView * __attribute__((aligned(__alignof__( ::java::lang::Object)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_AsyncBoxView$FlushTask__
