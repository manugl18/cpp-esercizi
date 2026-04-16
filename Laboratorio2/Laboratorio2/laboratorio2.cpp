#include <iostream>
#include "Libro.h" // Inclusione del tuo file
#include "Money.h"
using namespace std;

int main() {

    Libro libro("ciao", 1200);
    cout << libro.get_anno();

    Money portafoglio(10, 80); // 10 Euro e 80 Cent
    Money regalo(5, 50);      // 5 Euro e 50 Cent

    // Testiamo l'operatore +
    Money totale = portafoglio + regalo;
    cout << portafoglio;

    // Verifichiamo il risultato
    // Dovrebbe uscire: 16 Euro e 30 Cent (perché 80+50=130 cent -> 1 euro e 30)
    cout << "Hai nel portafoglio: " << portafoglio.get_euros() << "," << portafoglio.get_cents() << " Euro" << endl;
    cout << "Ricevi in regalo: " << regalo.get_euros() << "," << regalo.get_cents() << " Euro" << endl;
    cout << "---------------------------" << endl;
    cout << "TOTALE: " << totale.get_euros() << " Euro e " << totale.get_cents() << " Centesimi" << endl;

    return 0;
    
}