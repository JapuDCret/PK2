#include "stack.h"
#include "emtpy_stack_exception.h"


int Stack::push(int key){
  Element *neu = new Element {key, top};
  if (neu != nullptr){
    top =neu;
    return 1;
  }
  return 0;
}

int Stack::pop(){
  int k = -1;
  if (top != nullptr){
    Element *tmp = top;
    k = top->key;
    top = top->next;
    delete tmp;
    
    return k;
  }
  throw emtpy_stack_exception("stack was empty");
}
