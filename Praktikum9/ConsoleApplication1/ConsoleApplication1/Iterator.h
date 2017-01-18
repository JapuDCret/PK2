#ifndef ITERATOR_H_
#define ITERATOR_H_

namespace pk2 {
  class Iterator {
  private:
  
  public:
    /* Liefert den Wert true genau dann, wenn mindestens ein
            Element in der Liste ist, welches noch nicht mit der Funktion next() betrachtet
            wurde. */
	  virtual bool hasNext() = 0;
  
    /* Liefert den nächsten Text aus der Liste */
	  virtual const char* next() = 0;
  };
}

#endif