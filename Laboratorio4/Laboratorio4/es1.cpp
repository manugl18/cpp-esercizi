#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "link.h"
#include "llist.h"
#include "listTest.h"

void order_decr_list(LList<Item>& L1, LList<Item>& ordinata) {

	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) {

		//recupero il valore da inserire.
		Item da_inserire = L1.getValue();
		bool inserito = false;
		ordinata.moveToStart();

		//scorro la lista vuota (al primo ciclo non entra).
		while (ordinata.currPos() < ordinata.length()) {
			if (da_inserire.key() > ordinata.getValue().key()) {
				ordinata.insert(da_inserire);
				inserito = true;
				break;
			}
			//se l'elemento da inserire non è maggiore dell'elemento nella lista "ordinata"
			//confronto con il prossimo elemento.
			ordinata.next();
		}
		
		//se dopo il while non è stato inserito nessun valore lo aggiugne qua.
		if (!inserito) ordinata.append(da_inserire);

	}
}
// Main routine 
int main(int argc, char** argv) {

	LList<Item> L1;
	LList<Item> L2;
	LList<Item> L3;
	LList<Item> ordinata;
	L1.insert(Item(5));
	L1.insert(Item(1));
	L1.insert(Item(3));

	L2.insert(Item(1));
	L2.insert(Item(2));

	L1.moveToStart();

	while (L1.length() > 0) {
		Item i = L1.getValue();
		L3.append(i);
		L1.remove();

	}
	L2.moveToStart();
	while (L2.length() > 0) {
		Item i = L2.getValue();
		L3.append(i);
		L2.remove();
	}
	order_decr_list(L3, ordinata);
	lprint<Item>(ordinata);


	return 0;
}