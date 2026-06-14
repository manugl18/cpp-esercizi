#include <list>
#include <iostream>

using namespace std;

int main() {

	list<int> lista = { 1, 22, 4, 31, 4, 13 };
	list<int>::iterator it;

	it = lista.begin();
	lista.insert(++it, 5); // in questo momento It punta al 22 percio la posizine avanza in "automatico". Nelle LList il cursore non punta ai nodi percio rimane fisso
	lista.insert(it, 15);

	for (it = lista.begin(); it != lista.end(); it++) {
		cout << *it << " ";
	}
	return 0;

	//RICORDA BENE: quando si elimina un elemento da una lista (erase) viene cancellato fisicamente l'iterator. erase() restituisce un nuovo iterator che punta al nodo successivo.
}