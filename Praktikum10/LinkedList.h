#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Eminem.h"

namespace pk2 {
	template<class T>
	class LinkedList
	{
	private:
		Eminem<T>* first;
		Eminem<T>* last;
	
	public:
		/* Erzeugt eine leere Liste. */
		LinkedList();
	
	
		/* Fuegt den Text (in konstanter Zeit) an der letzten */
		/* Listenposition hinzu. */
		/* Liefert den Wert 1, wenn das Element eingefuegt werden */
		/* konnte. Ansonsten wird der Wert 0 geliefert. */
		int append(T* text);
	
	
		/* Fuegt ein neues Element an der Position p ein. */
		/* Das erste Element der Liste befindet sich an der */
		/* Position 0. */
		/* Das Element, das sich aktuell an der Position p befindet,*/
		/* wird nach rechts geschoben. */
		/* Falls sich weniger als p Elemente in der Liste befinden, */
		/* wird der Text am Ende angefuegt. */
		int insert(T* text, int p);
	
	
		/* Loescht das Element an der Position p. Das erste */
		/* Element befindet sich an der Position 0. */
		/* Falls das p-te Element nicht existiert, wird das letzte */
		/* Element geloescht. Die Anzahl der geloeschten Elemente */
		/* wird als Funktionswert geliefert. */
		int remove(int p);
		
		
		/* Liefert den Text an der p-ten Listenposition. */
		/* Das erste Listenelement befindet sich an der Position 0. */
		/* Falls das p-te Element nicht existiert, wird nullptr */
		/* geliefert. */
		T* get(int p);
		
		
		/* Berechnet den Index des ersten Elements, das den Text */
		/* text enthaelt. Falls kein Element den gesuchten Text */
		/* enthaelt, wird -1 geliefert. */
		int index_of(T* content);
		
		
		/* Liefert den Text des ersten Elements der Liste (in */
		/* konstanter Zeit). */
		T* get_first() const { return first->get_content(); }
		
		
		/* Liefert den Text des letzten Elements der Liste (in */
		/* konstanter Zeit). */
		T* get_last() const { return last->get_content(); };
		
		
		/* Besucht alle Elemente der Liste und ruft fuer jedes */
		/* Element die Funktion work auf. */
		void visit_all(void (*work)(T*));	};
}

#endif