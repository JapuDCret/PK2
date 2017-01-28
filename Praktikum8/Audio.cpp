#include <iostream>
#include <string>

#include "Audio.h"

using namespace std;

void Audio::druckeDaten() {
	cout << "Bild: { id:" << getId() << ", titel:" << getTitel() << ", jahr" << getJahr() << ", alter:" << alter() << ", interpret:" << getInterpret() << ", dauer:" << getDauer() << " }" << endl;
}