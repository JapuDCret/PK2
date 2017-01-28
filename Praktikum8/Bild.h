#ifndef BILD_H_
#define BILD_H_

#include <iostream>
#include <string>

#include "Medium.h"

using namespace std;

class Bild : public Medium {
private:
	string ort;
public:
	Bild(int id2, string titel2, int jahr2, string ort2) : Medium(id2, titel2, jahr2), ort(ort2) {};
	inline string getOrt() { return ort; }
	void druckeDaten();
};

#endif