//Scrivere una funzione template template <typename E> void Reverse(LStack<E>& S)
//per invertire una pila(stack) sfruttando la funzione di copia di una pila vista a lezione
//LstackTransfer(LStack<E>& S1, LStack<E>& S2)
#include <iostream>
#include <cstdlib>

using namespace std;

#include "lstack.h"
#include "LStackTest.h"

using namespace std;

template <typename E> void Reverse(LStack<E>& S) {
	LStack<E> S2;
	LstackTransfer(S, S2);

	int l = S.length();
	S.clear();
	for (int i = 0; i < l; i++) {
		E it = S2.pop();
		S.push(it);
	}
}

// Main routine 
int main(int argc, char** argv) {
	LStack<Item> S;
	Item temp1(10);
	Item temp2(20);
	Item temp3(30);

	S.push(temp1);
	S.push(temp2);
	S.push(temp3);

	Lstackprint(S);
	cout << "\n";
	Reverse(S);
	Lstackprint(S);
	return 0;
}