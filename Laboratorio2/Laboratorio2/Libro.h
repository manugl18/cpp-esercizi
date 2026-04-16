#pragma once 
#include <string>
#include <iostream>

using namespace std;

class Libro {
private:
    string titolo;
    int anno;

public:
    // Costruttore con parametri di default
    Libro(string titolo = "", int anno = 0);

    //Getter
    string get_titolo();
    int get_anno();

    //Setter
    void set_titolo(string titolo);
    void set_anno(int anno);
};


inline Libro::Libro(string titolo, int anno) {
    this->titolo = titolo;
    this->anno = anno;
}

// GETTER
inline string Libro::get_titolo() {
    return this->titolo;
}

inline int Libro::get_anno() {
    return this->anno;
}

// SETTER
inline void Libro::set_titolo(string titolo) {
    this->titolo = titolo;
}

inline void Libro::set_anno(int anno) {
    this->anno = anno;
}