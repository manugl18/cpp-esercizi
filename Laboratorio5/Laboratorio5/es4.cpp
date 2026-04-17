//Esercizio 4:
//Scrivere un programma per il calcolo della sequenza dei primi N numeri della sequenza di Fibonacci(1 1
//	2 3 5 8 13 21 34 55 89 144, …) che utilizzi uno stack per generare la sequenza e per memorizzarla.
//	Successivamente creare una lista singolarmente concatenata, estrarre tutti gli elementi dallo stack e
//	inserirli nella lista, con inserimento in testa.Visualizzare la lista.


#include <iostream>
#include <string>

#include "lstack.h"
#include "LStackTest.h"
#include "llist.h"

using namespace std;

void generaFibonacci(LStack<Item>& s1, int n) {

	Item penultimo;
	Item ultimo;
	Item nuovo;
	s1.push(Item(1));
	s1.push(Item(1));

	for (int i = 0; i < n-2; i++) {
		// l'elemento in cima e' l'ultimo elemento e quello prima il penultimo
		ultimo = s1.pop();
		penultimo = s1.pop();
		Item nuovo(penultimo.key()+ultimo.key());

		// per rimettere in ordine inserisco in questo modo poiche quello piu in cima deve essere il nuovo.
		s1.push(penultimo);
		s1.push(ultimo);
		s1.push(nuovo);
	}
}
int main() {

	LStack<Item> s1;
	LList<Item> l1;
	int n0 = 0;
	int n1 = 1;
	int sum = 0;
	int n;
	cout << "Inserisci un numero N: ";
	cin >> n;

	generaFibonacci(s1, n);
	Lstackprint(s1);
	
	while (s1.length() > 0) {
		l1.insert(s1.pop());
	}

}