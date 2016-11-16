#ifndef AUDIO_H_
#define AUDIO_H_

#include <iostream>
#include <string>

#include "Medium.h"

using namespace std;

class Audio : public Medium {
private:
	string interpret;
	int dauer;
public:
	Audio(int id2, string titel2, int jahr2, string interpret2, int dauer2) : Medium(id2, titel2, jahr2), interpret(interpret2), dauer(dauer2) {};
	inline string getInterpret() { return interpret; }
	inline int getDauer() { return dauer; }
	void druckeDaten();
};

#endif