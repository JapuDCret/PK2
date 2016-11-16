#ifndef MEDIUM_H_
#define MEDIUM_H_

#include <string>

using namespace std;

class Medium {
private:
	int id;
	string titel;
	int jahr;
public:
	Medium(int id2, string titel2, int jahr2) : id(id2), titel(titel2), jahr(jahr2) {};
	inline int getId() { return id; }
	inline string getTitel() { return titel; }
	inline int getJahr() { return jahr; }
	inline int alter() {
		return 2016-jahr;
	}
	virtual void druckeDaten() = 0;
};

#endif