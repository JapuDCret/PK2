#include <iostream>
#include <string>

#include "Bild.h"

using namespace std;

void Bild::druckeDaten() {
	cout << "Bild: { id:" << getId() << ", titel:" << getTitel() << ", jahr" << getJahr() << ", alter:" << alter() << ", ort:" << ort << " }" << endl;
}


//