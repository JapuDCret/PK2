#ifndef STACK_H_
#define STACK_H_

class Stack{
 private:
  struct Element{
    int key;
    Element *next;

    Element(int k, Element* next) : key {k}, next {next} {}
  };
  Element *top;

 public:
  Stack() : top {nullptr} {}
  int push(int key);
  int pop();

};

#endif