#pragma once

#include <iostream>
#include <cstdlib>
#include <time.h>  // Used by timing functions
using namespace std;

#include "llist.h"


// Your basic int type as an object.
class Prodotto {
private:
	string codice;
	string nome_prodotto;
	int quantita;
public:
	Prodotto(string codice = " ", string nome_prodotto = " ", int quantita = 0)
	{
		this->codice = codice;
		this->nome_prodotto = nome_prodotto;
		this->quantita = quantita;
	}
	string getCodice() const { return this->codice; }
	string getNomeProdotto() const { return this->nome_prodotto; }
	int getQuantita() const { return this->quantita; }
	void setQuantita(int quantita) { this->quantita = quantita; }
};

struct ricetta {
	int numero;
	string descrizione;
	string ingrediente1;
	int quantita_ingr1;
	string ingrediente2;
	int quantita_ingr2;
};

class Item {
private:
	ricetta ric;
public:
	Item() {}
	Item(ricetta r) { this->ric = r; }
	ricetta getRicetta() const { return this->ric; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Prodotto& i)
{
	return s << "(" << i.getCodice() << " " << i.getNomeProdotto() << " " << i.getQuantita()<<")";
}

inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getRicetta().numero << " " << i.getRicetta().descrizione << " " << i.getRicetta().ingrediente1 << "-" << i.getRicetta().quantita_ingr1 << " " << i.getRicetta().ingrediente2 << "-" << i.getRicetta().quantita_ingr2 << ")";
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




