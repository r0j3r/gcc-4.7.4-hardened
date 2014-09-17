
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_Collections__
#define __java_util_Collections__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>


class java::util::Collections : public ::java::lang::Object
{

  static jboolean isSequential(::java::util::List *);
  Collections();
public:
  static ::java::util::Set * emptySet();
  static ::java::util::List * emptyList();
  static ::java::util::Map * emptyMap();
public: // actually package-private
  static jint compare(::java::lang::Object *, ::java::lang::Object *, ::java::util::Comparator *);
public:
  static jint binarySearch(::java::util::List *, ::java::lang::Object *);
  static jint binarySearch(::java::util::List *, ::java::lang::Object *, ::java::util::Comparator *);
  static void copy(::java::util::List *, ::java::util::List *);
  static ::java::util::Enumeration * enumeration(::java::util::Collection *);
  static void fill(::java::util::List *, ::java::lang::Object *);
  static jint indexOfSubList(::java::util::List *, ::java::util::List *);
  static jint lastIndexOfSubList(::java::util::List *, ::java::util::List *);
  static ::java::util::ArrayList * list(::java::util::Enumeration *);
  static ::java::lang::Object * max(::java::util::Collection *);
  static ::java::lang::Object * max(::java::util::Collection *, ::java::util::Comparator *);
  static ::java::lang::Object * min(::java::util::Collection *);
  static ::java::lang::Object * min(::java::util::Collection *, ::java::util::Comparator *);
  static ::java::util::List * nCopies(jint, ::java::lang::Object *);
  static jboolean replaceAll(::java::util::List *, ::java::lang::Object *, ::java::lang::Object *);
  static void reverse(::java::util::List *);
  static ::java::util::Comparator * reverseOrder(::java::util::Comparator *);
  static ::java::util::Comparator * reverseOrder();
  static void rotate(::java::util::List *, jint);
  static void shuffle(::java::util::List *);
  static void shuffle(::java::util::List *, ::java::util::Random *);
  static jint frequency(::java::util::Collection *, ::java::lang::Object *);
  static jboolean addAll(::java::util::Collection *, JArray< ::java::lang::Object * > *);
  static jboolean disjoint(::java::util::Collection *, ::java::util::Collection *);
  static ::java::util::Set * singleton(::java::lang::Object *);
  static ::java::util::List * singletonList(::java::lang::Object *);
  static ::java::util::Map * singletonMap(::java::lang::Object *, ::java::lang::Object *);
  static void sort(::java::util::List *);
  static void sort(::java::util::List *, ::java::util::Comparator *);
  static void swap(::java::util::List *, jint, jint);
  static ::java::util::Collection * synchronizedCollection(::java::util::Collection *);
  static ::java::util::List * synchronizedList(::java::util::List *);
  static ::java::util::Map * synchronizedMap(::java::util::Map *);
  static ::java::util::Set * synchronizedSet(::java::util::Set *);
  static ::java::util::SortedMap * synchronizedSortedMap(::java::util::SortedMap *);
  static ::java::util::SortedSet * synchronizedSortedSet(::java::util::SortedSet *);
  static ::java::util::Collection * unmodifiableCollection(::java::util::Collection *);
  static ::java::util::List * unmodifiableList(::java::util::List *);
  static ::java::util::Map * unmodifiableMap(::java::util::Map *);
  static ::java::util::Set * unmodifiableSet(::java::util::Set *);
  static ::java::util::SortedMap * unmodifiableSortedMap(::java::util::SortedMap *);
  static ::java::util::SortedSet * unmodifiableSortedSet(::java::util::SortedSet *);
  static ::java::util::Collection * checkedCollection(::java::util::Collection *, ::java::lang::Class *);
  static ::java::util::List * checkedList(::java::util::List *, ::java::lang::Class *);
  static ::java::util::Map * checkedMap(::java::util::Map *, ::java::lang::Class *, ::java::lang::Class *);
  static ::java::util::Set * checkedSet(::java::util::Set *, ::java::lang::Class *);
  static ::java::util::SortedMap * checkedSortedMap(::java::util::SortedMap *, ::java::lang::Class *, ::java::lang::Class *);
  static ::java::util::SortedSet * checkedSortedSet(::java::util::SortedSet *, ::java::lang::Class *);
  static ::java::util::Queue * asLifoQueue(::java::util::Deque *);
  static ::java::util::Set * newSetFromMap(::java::util::Map *);
private:
  static const jint LARGE_LIST_SIZE = 16;
public:
  static ::java::util::Set * EMPTY_SET;
  static ::java::util::List * EMPTY_LIST;
  static ::java::util::Map * EMPTY_MAP;
private:
  static ::java::util::Collections$ReverseComparator * rcInstance;
  static ::java::util::Random * defaultRandom;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_Collections__
