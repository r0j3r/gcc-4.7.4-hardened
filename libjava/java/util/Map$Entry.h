
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_Map$Entry__
#define __java_util_Map$Entry__

#pragma interface

#include <java/lang/Object.h>

class java::util::Map$Entry : public ::java::lang::Object
{

public:
  virtual ::java::lang::Object * getKey() = 0;
  virtual ::java::lang::Object * getValue() = 0;
  virtual ::java::lang::Object * setValue(::java::lang::Object *) = 0;
  virtual jint hashCode() = 0;
  virtual jboolean equals(::java::lang::Object *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_util_Map$Entry__
