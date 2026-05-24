#include <iostream>
#include <stdlib.h>
#include <string>
#include "symbol_table_item.h"
#include "bst.h"
#include <fstream>

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
	return 0;
}