#include <iostream>
#include <string>

#include "Medium.h"
#include "Bild.h"
#include "Audio.h"

using namespace std;

int main(void) {
	cout << "Starte Programm.." << endl << endl;
	
	Medium * medien[2];
	
	Bild * b = new Bild(1, "nen cooles Bild", 1999, "Norwegen");
	Audio * a = new Audio(2, "Darude Sandstorm", 1989, "Darude", 420);
	
	medien[0] = b;
	medien[1] = a;
	
	for(int i=0; i < 2; i++) {
		cout << "medium[" << i << "] > ";
		medien[i]->druckeDaten();
	}
	
	cout << "Stoppe Programm.." << endl;
	return 0;
}