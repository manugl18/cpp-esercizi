#include <iostream>
#include <string>

using namespace std;

#include "link.h"
#include "llist.h"
#include "laboratorio4_es2_listTest.h"


int check(LList<Item>& lista, string provincia, string citta) {
	for (lista.moveToStart(); lista.currPos() < lista.length(); lista.next()) {
		if (lista.getValue().getProvincia() == provincia) {
			if (lista.getValue().getCitta() == citta) {
				return 0;
			}else {
				Item i = lista.remove();
				i.setCitta(citta);
				lista.insert(i); // Inserisce il nodo aggiornato nella stessa posizione
				return 2;
			}
		}
	}
    // devo scorrere tutta la lista e poi se non e' presente inserisco
	lista.append(Item(provincia, citta));
	return 1;
}
int main(int argc, char** argv) {

    LList<Item> lista;

    // Popoliamo la lista iniziale
    lista.append(Item("pr", "parma"));
    lista.append(Item("mi", "milano"));

    cout << "--- LISTA INIZIALE ---" << endl;
    lprint(lista);

    // TEST CASO A: Abbreviazione e citta' esistono
    cout << "Test A (Cerco 'pr', 'parma'):" << endl;
    int risA = check(lista, "pr", "parma");
    cout << "Risultato atteso: 0 | Risultato ottenuto: " << risA << endl << endl;

    // TEST CASO B: Abbreviazione non esiste (deve aggiungerla in coda)
    cout << "Test B (Cerco 'to', 'torino'):" << endl;
    int risB = check(lista, "to", "torino");
    cout << "Risultato atteso: 1 | Risultato ottenuto: " << risB << endl << endl;

    // TEST CASO C: Abbreviazione esiste ma citta' e' diversa (deve aggiornarla)
    cout << "Test C (Cerco 'mi', 'milan'):" << endl;
    int risC = check(lista, "mi", "milan");
    cout << "Risultato atteso: 2 | Risultato ottenuto: " << risC << endl << endl;

    // VERIFICA FINALE
    cout << "--- LISTA FINALE ---" << endl;
    lprint(lista);

    return 0;
}