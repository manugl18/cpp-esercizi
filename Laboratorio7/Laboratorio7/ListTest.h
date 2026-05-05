#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "list.h"

class Item {
private:
	string s;
public:
	Item(string s = " ") {
		this->s = s;
	}

	string getString() const { return s; }

	bool operator<(const Item& other) const {
		if (this->s < other.getString()) return true;
		else return false;
	}
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.getString();
}

// Assert: If "val" is false, print a message and terminate
// the program
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

