#pragma once
#include <string>
#include <iostream>
#include "lqueue.h"
using namespace std;
string maxKey = "";

class Item {
private:
	string nome;
	float tiratura;
	string sede;
	int anno;
public:
	Item(string nome = "", float tiratura = 0, string sede=maxKey, int anno = 0) {
		this->nome = nome;
		this->tiratura = tiratura;
		this->sede = sede;
		this->anno = anno;
	}
	int null()
	{
		return sede == maxKey;
	}
	string key() const {
		return sede;
	}
	string getNome() const {
		return nome;
	}
	void setNome(string nome) {
		this->nome = nome;
	}
	float getTiratura() const {
		return tiratura;
	}
	int getAnno() const {
		return anno;
	}
	void show(ostream& os = cout)
	{
		os << "(" << nome << "," << tiratura << "," << sede << "," << anno << ") ";
	}
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
  { return s << "(" << i.getNome() << "," << i.getTiratura() << "," << i.key() << "," << i.getAnno() << ")"; }
 
// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}
// Print the queue
template <typename E>
void Lqueueprint(LQueue<E>& Q) {
	for (int i = 0; i < Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}
