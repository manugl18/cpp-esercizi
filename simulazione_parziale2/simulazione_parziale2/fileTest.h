#pragma once

#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;

#include "list.h"

class Item {
private:
	int num_biglietto;
	string nome;
	string cognome;
public:
	Item(int num_biglietto = 0, string nome = " ", string cognome = " ")
	{
		this->num_biglietto = num_biglietto;
		this->nome = nome;
		this->cognome = cognome;
	}
	int getNumBiglietto() const {
		return this->num_biglietto;
	}
	string getNome() const {
		return this->nome;
	}
	string getCognome() const {
		return this->cognome;
	}
	void setNumBiglietti(int n_biglietto) {
		this->num_biglietto = n_biglietto;
	}
	void setNome(string nome) {
		this->nome = nome;
	}
	void setCognome(string cognome) {
		this->cognome = cognome;
	}
};

inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.getNome() << " " << i.getCognome() << " " << i.getNumBiglietto() << " ";
}

inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

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

class Premio {
private:
	string premio;
	float euro;
public:
	//ctor
	Premio(string premio = " ", float euro)
	{

	}
};




