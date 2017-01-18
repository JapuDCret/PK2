#include "ListIterator.h"
#include "stdafx.h"

using namespace pk2;

/* Liefert den Wert true genau dann, wenn mindestens ein
      Element in der Liste ist, welches noch nicht mit der Funktion next() betrachtet
      wurde. */
bool ListIterator::hasNext() {
  return ListIterator::list.get(ListIterator::pos) != nullptr;
}

/* Liefert den nächsten Text aus der Liste */
const char* ListIterator::next() {
  const char* tmp = ListIterator::list.get(ListIterator::pos);
  
  ListIterator::pos++;
  
  return tmp;
}