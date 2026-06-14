#include <iostream>
#include <stdlib.h>
#include <string>
#include "symbol_table_item.h"
#include "bst.h"
#include "classi.h"
#include <fstream>

bool isNumeric(string str) {
	for (char ch : str) {
		if (!isdigit(ch)) {
			return false;
		}
	}
	return true;
}
int main() {

	BST<Item, Key> bst, bst2;
	int key;
	string value;
	ifstream myfile("info.dat");

	if (myfile.is_open()) {
		while (myfile >> key >> value) {
			//l'operatore >> converte in automatico da str a int. Token si usa nel getline.
			bst.insert(Item(key, value));

		}
		myfile.close();
	}
	else {
		cout << "Impossibile aprire il file";
	}
	bst.show(cout);

	cout << "\nInserire nuove coppie id (digita un numero negativo per terminare)\n";

	while (true) {
		cout << "Inserisci: ";
		cin >> key >> value;
		if (key < 0) {
			break;
		}
		bst2.insert(Item(key, value));
	}


	bst.balance();
	bst2.balance();

	cout << "BST1\n";
	bst.show_PO(cout);
	cout << "\nBST2\n";
	bst2.show_PO(cout);

	LList<Item> lista;

	bst.merge(lista, bst2.getRoot());

	lprint(lista);

	//----------------------------------------------------------------------------------------------

	ifstream myfile2("telefoni.txt");
	BST<ItemPersona, string> bstNome;
	BST<ItemTelefono, string> bstTel;
	string ufficio, nomeCognome, telefono;

	while (getline(myfile2, ufficio, ',')) {
		getline(myfile2, nomeCognome, ',');
		getline(myfile2, telefono);

		bstNome.insert(ItemPersona(nomeCognome, ufficio));
		bstTel.insert(ItemTelefono(telefono, nomeCognome));
	}

	bstNome.balance();
	bstTel.balance();

	bstNome.show_IN(cout);
	bstTel.show_IN(cout);

	int l = bstTel.tree_size(bstTel.getRoot()); // numero di nodi dell'albero

	//stampo gli elementi di entrambi gli alberi come sono scritti nel file
	for (int i = 0; i < l; i++) {
		ItemTelefono It = bstTel.select(i); // prendo un elemento dell'albero dei telefoni e poi grazie al NOME cerco nell'altro albero la persona corrispondente
		ItemPersona Ip = bstNome.search(It.getNome());

		if (Ip.key() != "") {
			cout << Ip.getUfficio() << ", " << Ip.key() << ", " << It.key() << endl;
		}
	}


	string stringa;
	// Svuota il buffer se prima nel main hai usato un "cin >>"
	cin.ignore();
	while (true) {
		cout << "Inserisci un nome o un numero: ";
		getline(cin, stringa); // uso getline per prendere anche gli spazi.

		// verifico se nella stringa ci siano solo numeri
		if (isNumeric(stringa)) {
			ItemTelefono Itel = bstTel.search(stringa);
			if (Itel.key() != "") {
				ItemPersona Iper = bstNome.search(Itel.getNome());
				cout << Iper.getUfficio() << ", " << Iper.key() << ", " << Itel.key() << endl;
			}
			else {
				cout << "errore\n";
			}
		}
		// se la stringa non sono numeri cerco la persona e stampo tutte le altre che lavorano nello stesso ufficio
		else {
			ItemPersona Iper = bstNome.search(stringa);
			if (Iper.key() != "") {
				cout << "Persone che lavorano nello stesso ufficio di " << Iper.key() << ":" << endl;
				for (int i = 0; i < l; i++) {
					ItemPersona Iper2 = bstNome.select(i);
					if (Iper.getUfficio() == Iper2.getUfficio() && Iper.key() != Iper2.key()) cout << Iper2.key() << endl;
				}
			}
			else {
				cout << "errore\n";
			}
		}
	}
	return 0;
}