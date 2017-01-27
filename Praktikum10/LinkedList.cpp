#include "LinkedList.h"

using namespace pk2;
	
	
/* Erzeugt eine leere Liste. */
template<class T>
LinkedList<T>::LinkedList() {
	LinkedList::first = nullptr;
	LinkedList::last = nullptr;
}


/* Fuegt den Text (in konstanter Zeit) an der letzten */
/* Listenposition hinzu. */
/* Liefert den Wert 1, wenn das Element eingefuegt werden */
/* konnte. Ansonsten wird der Wert 0 geliefert. */
template<class T>
int LinkedList<T>::append(T* text)
{
	Eminem<T>* tmp = new Eminem<T>(text);
	
	if(tmp)//was object created?
	{
		if(last)
		{
			LinkedList::last->set_next(tmp);
			LinkedList::last = tmp;
		}
		else
		{
			LinkedList::first = tmp;
			LinkedList::last = tmp;
		}
		
		return 1;
	}
	
	return 0;
}


/* Fuegt ein neues Element an der Position p ein. */
/* Das erste Element der Liste befindet sich an der */
/* Position 0. */
/* Das Element, das sich aktuell an der Position p befindet,*/
/* wird nach rechts geschoben. */
/* Falls sich weniger als p Elemente in der Liste befinden, */
/* wird der Text am Ende angefuegt. */
template<class T>
int LinkedList<T>::insert(T* content, int p)
{
	Eminem<T>* tmp = new Eminem<T>(content);
	
	if(tmp)//was object created?
	{
		int counter = 0;
		
		if(last)
		{
			Eminem<T>* iterator = LinkedList::first;
			
			while(iterator && (++counter < p))
			{
				iterator = iterator->get_next();
			}
			
			tmp->set_next(iterator->get_next());
			iterator->set_next(tmp);
		}
		else
		{
			LinkedList::first = LinkedList::last = tmp;
		}
		
		return counter;
	}
	
	return -1;
}


/* Loescht das Element an der Position p. Das erste */
/* Element befindet sich an der Position 0. */
/* Falls das p-te Element nicht existiert, wird das letzte */
/* Element geloescht. Die Anzahl der geloeschten Elemente */
/* wird als Funktionswert geliefert. */
template<class T>
int LinkedList<T>::remove(int p)
{
	int counter = 0;
	Eminem<T>* iterator = LinkedList::first;
	Eminem<T>* prev = iterator;
	
	if(iterator)
	{
		while(counter < p)
		{
			if(iterator->get_next())
			{
				prev = iterator;
				iterator = iterator->get_next();
			}
			else
			{
				break;
			}
			
			counter++;
		}
		
		if(prev == iterator)
		{
			LinkedList::first = LinkedList::last = nullptr;
		}
		else
		{
			prev->set_next(iterator->get_next());
			delete iterator;
		}
		return counter;
	}
	
	return -1;
}


/* Liefert den Text an der p-ten Listenposition. */
/* Das erste Listenelement befindet sich an der Position 0. */
/* Falls das p-te Element nicht existiert, wird nullptr */
/* geliefert. */
template<class T>
T* LinkedList<T>::get(int p)
{
	int counter = 0;
	Eminem<T>* iterator = LinkedList::first;
	
	while(counter++ < p)
	{
		if(!iterator)
			return nullptr;
		
		iterator = iterator->get_next();
	}
	
	if(!iterator)
		return nullptr;
	return iterator->get_content();
}


template<class T>
int compare(T* obj1, T* obj2)
{
	return ((*obj1) == (*obj2));
}


/* Berechnet den Index des ersten Elements, das den Text */
/* text enthaelt. Falls kein Element den gesuchten Text */
/* enthaelt, wird -1 geliefert. */
template<class T>
int LinkedList<T>::index_of(T* content)
{
	int counter = 0;
	Eminem<T>* iterator = LinkedList::first;
	
	while(iterator)
	{
		if(compare(iterator->get_content(), content))
			return counter;
		
		counter++;
		iterator = iterator->get_next();
	}
	
	return -1;
}


/* Besucht alle Elemente der Liste und ruft fuer jedes */
/* Element die Funktion work auf. */
template<class T>
void LinkedList<T>::visit_all(void (*work)(T* t))
{
	Eminem<T>* iterator = LinkedList::first;
	while(iterator)
	{
		work(iterator->get_content());
		iterator = iterator->get_next();
	}
}