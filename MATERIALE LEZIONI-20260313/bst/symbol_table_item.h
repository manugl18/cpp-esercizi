#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions
#include "llist.h"
#include <iostream>
using namespace std;

static int maxKey = 1000; // chiave nulla

typedef int Key; // si puo togliere (usare int)

class Item
{
private:
	string info;
public:
	Key keyval;
	Item()
	{
		keyval = maxKey;
		info = ""; // Buona pratica: inizializza anche info a zero!
	}

	// 2. IL NUOVO COSTRUTTORE CON PARAMETRI (Aggiunto da te)
	Item(Key k, string i)
	{
		keyval = k;
		info = i;
	}
	Key key() const
	{
		return keyval;
	}
	int null()
	{
		return keyval == maxKey;
	}


	// legge da tastiera i dati (chiave, valore) di un elemento
	int scan(istream& is = cin)
	{
		is >> keyval >> info;
		return !(cin.fail());
	}
	void show(ostream& os = cout)
	{
		os << keyval << " " << info << endl;
	}

	string getinfo() const { return info; }
};
void Assert(bool val, std::string s) {
	if (!val) { // Se il controllo fallisce (es. lista vuota)
		std::cout << "Errore critico (Assertion Failed): " << s << std::endl;
		exit(-1); // Blocca il programma
	}
}
inline ostream& operator<<(ostream& os, const Item& i)
{
	return os << "(" << i.key() << " " << i.getinfo() << ")";
}
template <typename E>
void lprint(LList<E>& L) {
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


#endif