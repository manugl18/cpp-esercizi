#include <list>
#include <iostream>
#include "llist.h"
#include "ListTest.h"
using namespace std;

int main() {

	LList<list<Item>> lista_di_liste;

    list<Item> lista1;
    list<Item> lista2;
    list<Item> lista3;
    list<Item> lista4;

    // --- FASE 2: Popoliamo le liste STL con Item a caso ---

    // Riempiamo la prima lista (es. 2 elementi)
    lista1.push_back(Item(10));
    lista1.push_back(Item(20));

    // Riempiamo la seconda lista (es. 1 elemento)
    lista2.push_back(Item(30));

    // Riempiamo la terza lista (es. 3 elementi)
    lista3.push_back(Item(90));
    lista3.push_back(Item(100));
    lista3.push_back(Item(60));

    // Riempiamo la quarta lista (es. 2 elementi)
    lista4.push_back(Item(70));
    lista4.push_back(Item(80));

    lista_di_liste.append(lista1);
    lista_di_liste.append(lista2);
    lista_di_liste.append(lista3);
    lista_di_liste.append(lista4);

    Item m = lista1.front();
    int max = m.key();

    for (lista_di_liste.moveToStart(); lista_di_liste.currPos() < lista_di_liste.length(); lista_di_liste.next()) {
        list<Item> lista = lista_di_liste.getValue();
        for (list<Item>::iterator it = lista.begin(); it != lista.end(); it++) {
            Item i = *it;
            if (i.key() > max) max = i.key();
        }
    }
    cout << max;
	return 0;
}