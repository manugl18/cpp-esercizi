#pragma once

#include <iostream>
using namespace std;

class Item {
private:
	int val;
	int indice;
	int indice_succ;
public:
	// costruttore vuoto
	Item() {
		val = 0;
		indice = 0;
		indice_succ = 0;
	}
	Item(int val, int indice, int indice_succ) {
		this->val = val;
		this->indice = indice;
		this->indice_succ = indice_succ;
	}

	int getVal() const { return val; }
	int getIndice() const { return indice; }
	int getIndiceSucc() const { return indice_succ; }

	bool operator<(const Item& other) const {
		return val < other.val;
	}
	bool operator>(const Item& other) const {
		return val > other.val;
	}
};




