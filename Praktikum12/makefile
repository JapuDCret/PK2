main : main.cpp stack.o stack.h
	c++ main.cpp -o main stack.o -std=c++11

stack.o : stack.cpp emtpy_stack_exception.h
	c++ stack.cpp -c -std=c++11

clear:
	rm main stack.o