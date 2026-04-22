#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
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
	int k;
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

	cout << "Inserisci una dimensione K <= 7: ";
	cin >> k;

	if (k > 7) {
		return 1;
	}
	Premio* premi = new Premio[k];
	int i = 0;
	ifstream myfile2("premi.txt");
	string premio;
	float euro;
	float somma_premi = 0;
	if (myfile2.is_open()) {
		while (myfile2 >> premio >> euro) {
			if (i > k - 1) break;
			premi[i] = Premio(premio, euro / 100);
			somma_premi += premi[i].getEuro();
			i++;
		}
		myfile2.close();
	}


	Premio temp = premi[0];
	premi[0] = premi[k - 1];
	premi[k - 1] = temp;

	LStack<Premio> stack;

	for (int i = k - 1; i >= 0; i--) {
		stack.push(premi[i]);
	}
	Lstackprint(stack);
	cout << "SOMMA TOTALE PREMI: " << somma_premi << "\n";


	bool inserito = true;
	LList <Item>appoggio;
	srand(time(0));
	for (int i = 0; i < k; i++) {
		inserito = true;
		//estraggo vincitore
		int numero = rand() % biglietti.length();
		biglietti.moveToPos(numero);
		Item vincitore = biglietti.getValue();

		if (appoggio.length() > 0) {
			for (appoggio.moveToStart(); appoggio.currPos() < appoggio.length(); appoggio.next()) {
				if (vincitore.getNome() == appoggio.getValue().getNome() && vincitore.getCognome() == appoggio.getValue().getCognome()) {
					i--;
					inserito = false;
					break;
				}
			}
			if (inserito) appoggio.append(vincitore);

		}
		else appoggio.append(vincitore);

	}

	appoggio.moveToStart();

	while (appoggio.currPos() < appoggio.length() && stack.length() > 0) {
		Premio p = stack.pop();
		Item vincitore = appoggio.getValue();

		cout << "Il premio " << p.getPremio()
			<< " viene attribuito a "
			<< vincitore.getNome() << " "
			<< vincitore.getCognome() << endl;

		appoggio.next();
	}
	return 0;
}
