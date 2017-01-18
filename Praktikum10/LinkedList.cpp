#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "ListIterator.h"

using namespace pk2;
  
/* Erzeugt eine leere Liste. */
LinkedList::LinkedList() {
  first = nullptr;
  last = nullptr;
  
  iterator = new ListIterator(this);
}

LinkedList::~LinkedList() {
  while(LinkedList::remove(0) != -1);
}

LinkedList::LinkedList(const LinkedList& list) {
  int pos = 0;
  char* tmp;
  while((tmp = (char*) list.get(pos)) != nullptr)
  {
    size_t keylen = strlen(tmp);
    char* tmp2 = (char *) malloc(keylen*sizeof(char));
    strcpy(tmp, tmp2);
    LinkedList::append(tmp2);
    pos++;
  }
}

/* Fuegt den Text (in konstanter Zeit) an der letzten */
/* Listenposition hinzu. */
/* Liefert den Wert 1, wenn das Element eingefuegt werden */
/* konnte. Ansonsten wird der Wert 0 geliefert. */
int LinkedList::append(const char* text)
{
  Eminem* tmp = new Eminem(text);
  
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
int LinkedList::insert(const char* text, int p)
{
  Eminem* tmp = new Eminem(text);
  
  if(tmp)//was object created?
  {
    int counter = 0;
    
    if(last)
    {
      Eminem* iterator = LinkedList::first;
      
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
int LinkedList::remove(int p)
{
  int counter = 0;
  Eminem* iterator = LinkedList::first;
  Eminem* prev = iterator;
  
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
const char* LinkedList::get(int p) const
{
  int counter = 0;
  Eminem* iterator = LinkedList::first;
  
  while(counter++ < p)
  {
    if(!iterator)
      return nullptr;
    
    iterator = iterator->get_next();
  }
  
  if(!iterator)
    return nullptr;
  return iterator->get_text();
}


int compare(const char* str1, const char* str2)
{
  int counter = 0;
  while(*(str1+counter) == *(str2+counter))
  {
    if(*(str1+counter) == '\0')
      return true;
    
    counter++;
  }
  return false;
}


/* Berechnet den Index des ersten Elements, das den Text */
/* text enthaelt. Falls kein Element den gesuchten Text */
/* enthaelt, wird -1 geliefert. */
int LinkedList::index_of(const char* text) const
{
  int counter = 0;
  Eminem* iterator = LinkedList::first;
  
  while(iterator)
  {
    if(compare(iterator->get_text(), text))
      return counter;
    
    counter++;
    iterator = iterator->get_next();
  }
  
  return -1;
}


/* Besucht alle Elemente der Liste und ruft fuer jedes */
/* Element die Funktion work auf. */
void LinkedList::visit_all(void (*work)(const char* t))
{
  Eminem* iterator = LinkedList::first;
  while(iterator)
  {
    work(iterator->get_text());
    iterator = iterator->get_next();
  }
}