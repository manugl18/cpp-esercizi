#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // 1. Array iniziale grezzo con duplicati
    vector<string> grezzi;
    grezzi.push_back("Kvaratskhelia");
    grezzi.push_back("Barella");
    grezzi.push_back("Dybala");
    grezzi.push_back("Barella"); // Duplicato intenzionale

    // Ordiniamo il vettore usando l'algoritmo sort [cite: 571]
    sort(grezzi.begin(), grezzi.end());

    // 2. Usiamo un set per eliminare i duplicati. 
    // Il set non accetta chiavi duplicate [cite: 420] e mantiene i dati ordinati[cite: 415].
    set<string> giocatoriUnici;
    for (vector<string>::iterator it = grezzi.begin(); it != grezzi.end(); it++) {
        giocatoriUnici.insert(*it); // Inserimento nel set [cite: 439]
    }

    // 3. Associamo a ogni giocatore un budget usando una map 
    map<string, float> asta;
    typedef pair<string, float> GiocatoreBudget; // [cite: 472]

    // Trasferimento dal set alla map
    for (set<string>::iterator itSet = giocatoriUnici.begin(); itSet != giocatoriUnici.end(); itSet++) {
        // Inseriamo con budget 0.0 usando la struttura pair [cite: 466, 473]
        asta.insert(GiocatoreBudget(*itSet, 0.0));
    }

    // Aggiorniamo un valore specifico usando find [cite: 485]
    map<string, float>::iterator target = asta.find("Dybala");
    if (target != asta.end()) { // [cite: 486]
        (*target).second = 45.5; // [cite: 488]
    }

    // Stampa finale
    cout << "--- Budget Asta ---" << endl;
    for (map<string, float>::iterator itMap = asta.begin(); itMap != asta.end(); itMap++) {
        cout << (*itMap).first << " -> Max " << (*itMap).second << " crediti" << endl;
    }

    return 0;
}