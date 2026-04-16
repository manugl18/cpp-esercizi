#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void esercizio1() {
    const int N = 5;
    int a[N] = {3,2,5,4,1};
    int b[N]; //{0, ‐3, 6, ‐9, 12}
    int c[N];
    int d[N];

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) b[i] = 3 * i;
        else b[i] = 3 * -i;
    }

    for (int i = 0, j = N - 1; i < N, j >= 0; i++, j--) {
        c[i] = a[i] + b[j];
    }

    for (int i = 0; i < N; i++) {
        if (a[i] > b[i]) d[i] = 1;
        else if (a[i] = b[i]) d[i] = 0;
        else d[i] = -1;
    }
    cout << "a:";
    for (int i = 0; i < N; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
    cout << "b:";
    for (int i = 0; i < N; i++) {
        cout << b[i] << ", ";
    }
    cout << endl;
    cout << "c:";
    for (int i = 0; i < N; i++) {
        cout << c[i] << ", ";
    }
    cout << endl;
    cout << "d:";
    for (int i = 0; i < N; i++) {
        cout << d[i] << ", ";
    }
}

void esercizio2() {
    const int N = 31;
    int num_a;
    int num_b;
    int count = 0;
    int disbonibile_a[N] = { 0 };
    int disbonibile_b[N] = { 0 };

    do {
        cout << "Persona A: Inserisci i giorni in cui sei libero";
        cin >> num_a;
        if (num_a > 0 && num_a <= 31) {
            disbonibile_a[num_a-1] = 1;
        }
    } while (num_a != 0);

    do {
        cout << "Persona B: Inserisci i giorni in cui sei libero";
        cin >> num_b;
        if (num_b > 0 && num_b <= 31) {
            disbonibile_b[num_b-1] = 1;
        }
    } while (num_b != 0);

    for (int i = 0; i < N; i++) {
        if (disbonibile_a[i] == 1 && disbonibile_b[i] == 1) cout << i+1 << endl;
    }
}
void esercizio3() {
    int numeri[3] = { 25, 9, 49 };

    for (int i = 0; i < 3; i++) {
        int x = 1;
        for (int j = 0; j < 100; j++) {
            x = 0.5 * (x + numeri[i] / x);
        }
        cout << x << endl;
    }
}

void esercizio4() {
    struct Libro {
        string titolo;
        string autore;
        int anno_edizione;
        int prezzo;
    };

    srand(static_cast<unsigned int>(time(NULL)));

    Libro libri[3]; // Array di 3 libri
    double somma = 0;
    double media;

    // INPUT DEI DATI
    for (int i = 0; i < 3; i++) {
        cout << "Inserisci il titolo del " << i + 1 << " libro: ";
        cin >> libri[i].titolo; // Salva direttamente nell'array
        cout << "Inserisci l'autore del " << i + 1 << " libro: ";
        cin >> libri[i].autore;
        cout << "Inserisci l'anno di edizione: ";
        cin >> libri[i].anno_edizione;

        libri[i].prezzo = rand() % 201; // Genera prezzo tra 0 e 200
        cout << "Prezzo assegnato: " << libri[i].prezzo << "euro\n\n";
    }

    // CALCOLI
    int max = libri[0].prezzo;
    int min = libri[0].anno_edizione;
    int indice_max = 0;
    int indice_min = 0;

    for (int i = 0; i < 3; i++) {
        somma += libri[i].prezzo;

        // Trova il libro più costoso
        if (libri[i].prezzo > max) {
            max = libri[i].prezzo;
            indice_max = i;
        }

        // Trova il libro più antico
        if (libri[i].anno_edizione < min) {
            min = libri[i].anno_edizione;
            indice_min = i;
        }
    }

    media = somma / 3.0;

    // STAMPA DEI RISULTATI
    cout << "Prezzo medio dei libri: " << media << " euro" << endl;

    cout << "Libro piu' costoso: " << libri[indice_max].titolo
        << " (" << max << " euro)" << endl;

    cout << "Libro piu' antico: " << libri[indice_min].titolo
        << " (Anno: " << min << ")" << endl;
}