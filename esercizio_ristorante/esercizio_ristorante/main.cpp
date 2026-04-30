#include <iostream>
#include <fstream>
#include <sstream>
#include "es1-listTest.h"

void bubblesort(List<Item>& L) {
    for (int i = 0; i < (L.length() - 1); i++) {
        for (int j = (L.length() - 1); j > i; j--) {
            L.moveToPos(j);
            Item it_j = L.getValue();
            L.moveToPos(j - 1);
            Item it_jj = L.getValue();
            if (it_jj.getRicetta().numero > it_j.getRicetta().numero) { // ordine crescente
                L.moveToPos(j);
                Item removed = L.remove();
                L.moveToPos(j - 1);
                L.insert(removed);
            }
        }
    }
}

int main() {

    //---------PARTE 1---------------
    ifstream myfile("dispensa.txt");
    LList<Prodotto> prodotti;
    LList<Item> ricette;

    if (myfile.is_open()) {
        string str, codice, nome_prodotto;
        int quantita;

        while (getline(myfile, codice, ';')) {
            getline(myfile, nome_prodotto, ';');
            getline(myfile, str);
            istringstream token(str);
            token >> quantita;

            int somma = quantita;
            for (prodotti.moveToStart(); prodotti.currPos() < prodotti.length();) {
                Prodotto p = prodotti.getValue();
                if (p.getCodice() == codice) {
                    somma += p.getQuantita();
                    prodotti.remove(); // remove() fa next in automatico
                }
                else {
                    prodotti.next();
                }
            }
            prodotti.append(Prodotto(codice, nome_prodotto, somma));
        }
        myfile.close();
    }
    else {
        cout << "Errore apertura file dispensa.txt" << endl;
    }

    lprint(prodotti);

    //-----------PARTE 2------------------------------
    ifstream myfile2("ricette.txt");

    if (myfile2.is_open()) {
        string str1, str2, str3;
        ricetta r;
        while (getline(myfile2, str1, ';')) {
            getline(myfile2, r.descrizione, ';');
            getline(myfile2, r.ingrediente1, ';');
            getline(myfile2, str2, ';');
            getline(myfile2, r.ingrediente2, ';');
            getline(myfile2, str3);

            istringstream token1(str1);
            istringstream token2(str2);
            istringstream token3(str3);
            token1 >> r.numero;
            token2 >> r.quantita_ingr1;
            token3 >> r.quantita_ingr2;

            ricette.append(Item(r));
        }
        myfile2.close();
    }
    else {
        cout << "Errore apertura file ricette.txt" << endl;
    }

    bubblesort(ricette);
    lprint(ricette);
    cout << "\n";

    //-----------PARTE 3------------------------------
    int numero_piatto;
    while (true) {
        cout << "Ehi cuoco, che piatto vuoi cucinare? ";
        cin >> numero_piatto;

        ricette.moveToPos(numero_piatto - 1);
        ricetta r = ricette.getValue().getRicetta();
        bool possibile = true;

        // Controllo disponibilita' ingredienti
        for (prodotti.moveToStart(); prodotti.currPos() < prodotti.length(); prodotti.next()) {
            Prodotto p = prodotti.getValue();
            if (p.getCodice() == r.ingrediente1 && p.getQuantita() < r.quantita_ingr1)
                possibile = false;
            if (p.getCodice() == r.ingrediente2 && p.getQuantita() < r.quantita_ingr2)
                possibile = false;
        }

        if (!possibile) {
            cout << "Ingredienti insufficienti!\n";
            continue;
        }

        // Sottrazione ingredienti
        for (prodotti.moveToStart(); prodotti.currPos() < prodotti.length();) {
            Prodotto p = prodotti.getValue();

            if (p.getCodice() == r.ingrediente1) {
                prodotti.remove();
                int nuova_q = p.getQuantita() - r.quantita_ingr1;
                prodotti.insert(Prodotto(p.getCodice(), p.getNomeProdotto(), nuova_q));
                prodotti.next(); // insert() non avanza il cursore, quindi next() e' necessario
            }
            else if (p.getCodice() == r.ingrediente2) {
                prodotti.remove();
                int nuova_q = p.getQuantita() - r.quantita_ingr2;
                prodotti.insert(Prodotto(p.getCodice(), p.getNomeProdotto(), nuova_q));
                prodotti.next();
            }
            else {
                prodotti.next();
            }
        }

        cout << "Piatto cucinato!\n";
        lprint(prodotti);
    }

    return 0;
}