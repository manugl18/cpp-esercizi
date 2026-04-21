#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "fileTest.h"
#include "llist.h"
using namespace std;

void bubble(LList<Item>& lista)
{
	for (int i = 0; i < (lista.length() - 1); i++) {
		//si usa j > i per non fare andare outofrange e anche perchè cosi non si controllano gli elementi gia in ordine 
		for (int j = lista.length() - 1; j > i; j--) {
			lista.moveToPos(j);
			Item i_dx = lista.getValue();
			lista.moveToPos(j - 1);
			Item i_sx = lista.getValue();

			//decrescente
			if (i_dx.getNumBiglietto() > i_sx.getNumBiglietto()) {
				//mi sposto di nuovo per poter cancellare l'elemento a destra
				lista.moveToPos(j);
				Item removed = lista.remove();
				lista.moveToPos(j - 1);
				lista.insert(removed);

			}
		}
	}


}

int main() {

	LList<Item> biglietti;
	string nome, cognome;
	int num_biglietto;
	ifstream myfile("biglietti.txt");

	if (myfile.is_open()) {
		while (myfile >> num_biglietto >> nome >> cognome) {
			//l'operatore >> converte in automatico da str a int. Token si usa nel getline.
			biglietti.append(Item(num_biglietto, nome, cognome));

		}
		myfile.close();
	}
	else {
		cout << "Impossibile aprire il file";
	}
	bubble(biglietti);
	lprint(biglietti);

	return 0;
}
