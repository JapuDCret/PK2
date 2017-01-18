#include "stack.h"
#include "emtpy_stack_exception.h"
#include <iostream>


int main(){
  try {
    Stack s;

    s.push(1);
    s.push(2);

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    
  } catch(emtpy_stack_exception& e) {
    std::cout << "An emtpy_stack_exception occurred. Message was \"" << e.what() << "\"" << std::endl;
  }

  return 0;
}
