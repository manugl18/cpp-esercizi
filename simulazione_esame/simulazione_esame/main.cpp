#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <list> 

#include "bst.h";
#include "lqueue.h";
#include "listTest.h"

using namespace std;

void es3(LQueue<Item>& q1, string str) {
	for (int i = 0; i < q1.length(); i++) {
		Item it = q1.dequeue();

		if (it.getNome() == str) {
			for (int j = 0; j < 2; j++) {
				q1.dequeue();
			}
			Item a = q1.frontValue();
			cout << a;
			break;
		}
		else {
			q1.enqueue(it);
		}
	}
}
int main() {
	float tiratura;
	string nome;
	string sede;
	int anno;

	string str1, str2;

	LQueue<Item> q1;
	BST<Item, string> albero_quotidiani;
	list<Item> L1;

	ifstream myfile("quotidiani.txt");
	if (myfile.is_open()) {
		while (getline(myfile, nome, ',')) {
			getline(myfile, str1, ',');
			getline(myfile, sede, ',');
			getline(myfile, str2);
			istringstream token(str1);
			token >> tiratura;
			istringstream token2(str2);
			token2 >> anno;

			if (tiratura > 7.1) {
				q1.enqueue(Item(nome, tiratura, sede, anno));
			}
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";
	Lqueueprint(q1);

	//es1---------------------------------------------------------------------------------
	for (int i = 0; i < q1.length(); i++)
	{
		Item it = q1.dequeue();
		bool inserito = true;
		int grandezza_albero = albero_quotidiani.tree_size(albero_quotidiani.getRoot());

		for (int j = 0; j < grandezza_albero; j++) {
			Item it2 = albero_quotidiani.select(j);

			// Se trovo una chiave identica
			if (it.key() == it2.key()) {
				inserito = false;
				break;
			}
		}
		if (inserito) {
			albero_quotidiani.insert(it);
		}

		q1.enqueue(it);
	}
	cout << endl << endl << "Q1: stampa albero" << endl;
	albero_quotidiani.balance();
	albero_quotidiani.show(cout);

	//es2----------------------------------------------------------------------------------------------------
	for (int i = 0; i < q1.length(); i++) {
		Item temp = q1.dequeue();
		L1.push_back(temp);
		q1.enqueue(temp);
	}


	list<Item>::iterator it = L1.begin();
	while (it != L1.end()) {
		if (it->getAnno() > 1886 && it->getAnno() < 1952) {
			Item temp = *it;
			it = L1.erase(it);
			L1.push_front(temp);
		}
		else {
			it++;
		}
	}


	cout << endl << endl << "L1: " << endl;
	for (list<Item>::iterator it = L1.begin(); it != L1.end(); it++) {
		cout << *it << " ";
	}

	//es3-----------------------------------------------------------------------------------------
	cout << endl;
	es3(q1, "Il Tirreno");
	
	//es4----------------------------------------------------------------------------------------------
	albero_quotidiani.modifica_valori();
	cout << endl << endl << "Q4: stampa albero" << endl;
	albero_quotidiani.show(cout);
	return 0;
}