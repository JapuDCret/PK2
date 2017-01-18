#include "emtpy_stack_exception.h"
#include <string>

emtpy_stack_exception::emtpy_stack_exception () {
  std::range_error::range_error();
}

emtpy_stack_exception::emtpy_stack_exception (const std::string& what_arg) {
  std::range_error::range_error(what_arg);
}

emtpy_stack_exception::emtpy_stack_exception (const char* what_arg) {
  std::range_error::range_error(what_arg);
}
