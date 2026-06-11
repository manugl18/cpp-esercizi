#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // 1. Creazione del vettore
    vector<string> projects;

    // 2. Travaso dei parametri da riga di comando al vettore
    for (int i = 1; i < argc; ++i) {
        projects.push_back(string(argv[i]));
    }

    // 3. Ricerca dell'elemento
    vector<string>::iterator j = find(projects.begin(), projects.end(), "Lab8"); // STL pensa e parla solo tramite iteratori.

    // 4. Controllo del risultato
    if (j == projects.end()) { // se l'elemento non viene trovato, find restituisce l'iteratore di fine. per trovare l'indice: j - projects.begin()
        cout << "Lab8 not found" << endl;
    }
    else {
        cout << "Lab8 found" << endl;
    }

    return 0;
}