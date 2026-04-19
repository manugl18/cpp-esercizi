#include <iostream>
#include "Lqueue.h"
#include "LQueueTest.h"

using namespace std;

int main() {

	int n_numeri = 0;
	LQueue<Item> coda;
	LQueue<Item> coda2;
	float n = 0;
	cout << "quanti numeri vuoi inserire? \n";
	cin >> n_numeri;
	cout << "Inserisci i numeri float: \n";

	for (int i = 0; i < n_numeri; i++) {
		cin >> n;
		coda.enqueue(Item(n));
	}
	// RICORDA BENE: Nelle CODE, l'ultimo elemento che inseriamo va IN FONDO ALLA CODA.
	int cnt = 0;
	while (coda.length() > 1) {
		int l = coda.length();
		for (int i = 0; i < l / 2; i++) {
			Item it1 = coda.dequeue();
			Item it2 = coda.dequeue();

			float valore = 0;
			switch (cnt % 4)
			{
			case(0): valore = it1.key() + it2.key();
				break;
			case(1): valore = it1.key() - it2.key();
				break;
			case(2): valore = it1.key() * it2.key();
				break;
			case(3): valore = it1.key() / it2.key();
				break;

			}
			coda.enqueue(Item(valore));
		}
		// questo controllo serve poiche se ho un numero dispari di elementi, l'elemento non coinvolto deve essere sempre in fondo alla coda.
		if (l % 2 != 0) {
			Item it1 = coda.dequeue();
			coda.enqueue(it1);
		}
		cnt++;
		cout << "Q1 is: ";
		Lqueueprint(coda);
		cout << "\n";
	}
	return 0;
}