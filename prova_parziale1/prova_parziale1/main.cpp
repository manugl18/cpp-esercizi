#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "fileTest.h"

using namespace std;

int main() {

	ifstream myfile("bigliettiVenduti.txt");
	LList<Item> biglietti_venduti;
	LList<Item> primi_biglietti_venduti;
	if (myfile.is_open()) {
		int num_biglietto;
		string nome, cognome, str;

		while (getline(myfile, str, ',')) {
			getline(myfile, nome, ',');
			getline(myfile, cognome);
			istringstream token(str);
			token >> num_biglietto;

			biglietti_venduti.append(Item(num_biglietto, nome, cognome));
		}
	}
	else {
		cout << "Errore apertura file";
	}
	lprint(biglietti_venduti);
	Item precedente;
	bool primo = true;

	for (biglietti_venduti.moveToStart(); biglietti_venduti.currPos() < biglietti_venduti.length(); biglietti_venduti.next()) {

		Item corrente = biglietti_venduti.getValue();

		if (primo || corrente.getNome() != precedente.getNome() || corrente.getCognome() != precedente.getCognome()) {

			cout << "primo biglietto acquistato da: "
				<< corrente.getNome() << " "
				<< corrente.getCognome() << " "
				<< corrente.getNumBiglietto() << endl;

			precedente = corrente;
			primo = false;
		}
	}
	return 0;
}