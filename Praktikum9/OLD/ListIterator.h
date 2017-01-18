#ifndef LISTITERATOR_H_
#define LISTITERATOR_H_

#include "Iterator.h"
#include "LinkedList.h"

namespace pk2 {
  class ListIterator :: public Iterator {
  private:
    LinkedList list;
    int pos = 0;
  
  public:
    /* Erzeugt eine leere Liste. */
    ListIterator(LinkedList list2) : list(list2) {};
    
    /* Liefert den Wert true genau dann, wenn mindestens ein
            Element in der Liste ist, welches noch nicht mit der Funktion next() betrachtet
            wurde. */
    bool hasNext();
  
    /* Liefert den nächsten Text aus der Liste */
    const char* next();
  }
}

#endif