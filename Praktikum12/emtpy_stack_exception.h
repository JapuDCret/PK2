#ifndef EMPTY_STACK_EXCEPTION_H_
#define EMPTY_STACK_EXCEPTION_H_

#include <stdexcept>
#include <string>

class emtpy_stack_exception : public std::range_error{
  public:
    explicit emtpy_stack_exception (const std::string& what_arg)
      : std::range_error(what_arg)
      {};
    
    explicit emtpy_stack_exception (const char* what_arg)
      : std::range_error(what_arg)
      {};
};

#endif
