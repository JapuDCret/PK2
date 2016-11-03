#include <stdio.h>
#include <iostream>
#include "Auto.h"

int main(void)
{
	printf("Hello World\n");
	
	std::cout << "Hello World" << std::endl;
	
	Auto* a1 = new Auto("BMW", 120);
	Auto* a2 = new Auto("Skoda", 70);
	
	std::cout << "Name: " << a1->name << " PS:" << a1->getPS() << std::endl;
	std::cout << "Name: " << a2->name << " PS:" << a2->getPS() << std::endl;
	
	return 0;
}