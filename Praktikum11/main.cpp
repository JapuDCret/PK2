#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;
using namespace pk2;

int main(void)
{
	cout << "Starte Programm.." << endl;
	Matrix<int> m(2);
	
	m.set(0,0,1);
	m.set(0,1,2);
	m.set(1,0,3);
	m.set(1,1,4);
	
	//cout << m << "*" << endl << m << "=";
	cout << m << "*" << endl << m << "=" << endl << *(m*m);
	
	cout << "Stoppe Programm.." << endl;
	return 0;
}