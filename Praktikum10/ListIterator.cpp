#include "ListIterator.h"

using namespace pk2;

/* Liefert den Wert true genau dann, wenn mindestens ein
			Element in der Liste ist, welches noch nicht mit der Funktion next() betrachtet
			wurde. */
bool ListIterator::hasNext() {
	return list->get(pos) != nullptr;
}

/* Liefert den nächsten Text aus der Liste */
template<class T>
T ListIterator::next() {
	T tmp = list->get(pos);
	
	pos++;
	
	return tmp;
}