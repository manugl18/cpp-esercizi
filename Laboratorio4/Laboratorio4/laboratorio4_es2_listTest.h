#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
//#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"

class Item {
private:
	string provincia;
	string citta;
public:
	Item(string provincia = "", string citta = "");
	string getProvincia() const;
	string getCitta() const;
	void setCitta(string citta);
};

inline Item::Item(string provincia, string citta) {
	this->provincia = provincia;
	this->citta = citta;
}
inline string Item::getProvincia() const {
	return this->provincia;
}
inline string Item::getCitta() const {
	return this->citta;
}
inline void Item::setCitta(string citta) {
	this->citta = citta;
}
inline ostream& operator<<(ostream& s, Item i) {
	return s << i.getCitta() << " " << i.getProvincia() << "; ";
}

inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}