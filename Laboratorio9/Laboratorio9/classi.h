#pragma once
#include <iostream>
#include <string>
#include "bst.h" 

using namespace std;

// --- PRIMO TIPO DI ITEM ---
// Chiave: Nome-Cognome (string) | Valore: Ufficio (string)
class ItemPersona {
private:
	string ufficio;
public:
	string nomeCognome; // chiave

	// Costruttore di default (fondamentale per il nullItem del BST)
	ItemPersona() {
		nomeCognome = "";
		ufficio = "";
	}

	ItemPersona(string nome, string uff) {
		nomeCognome = nome;
		ufficio = uff;
	}
	string getUfficio() const {
		return ufficio;
	}
	// Il metodo che il BST esige per poter ordinare i nodi
	string key() const {
		return nomeCognome;
	}
	
	void show(ostream& os = cout) {
		os << "Dipendente: " << nomeCognome << " | Ufficio: " << ufficio << endl;
	}
};

// --- SECONDO TIPO DI ITEM ---
// Chiave: Telefono (string) | Valore: Nome-Cognome (string)
class ItemTelefono {
private:
	string nomeCognome;
public:
	string telefono; //chiave

	ItemTelefono() {
		telefono = "";
		nomeCognome = "";
	}

	ItemTelefono(string tel, string nome) {
		telefono = tel;
		nomeCognome = nome;
	}

	string key() const {
		return telefono;
	}
	string getNome() const {
		return nomeCognome;
	}
	void show(ostream& os = cout) {
		os << "Tel: " << telefono << " | Intestatario: " << nomeCognome << endl;
	}
};

inline ostream& operator<<(ostream& os, ItemPersona& item) {
	item.show(os); // Richiama il metodo show interno alla classe
	return os;
}

// Operatore per la classe ItemTelefono
inline ostream& operator<<(ostream& os, ItemTelefono& item) {
	item.show(os); // Richiama il metodo show interno alla classe
	return os;
}