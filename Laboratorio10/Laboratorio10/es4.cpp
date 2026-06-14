#include <iostream>
#include <set>
#include <map>
#include <fstream>

using namespace std;

bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3) {
	map<string, set<int>>::iterator it = lotto.find(ruota);
	if (it == lotto.end()) {
		return 0;
	}
	int count = 0;
	for (int n : it->second) {
		if (n == n1 || n == n2 || n == n3) count++;
	}
	if (count == 3) return 1;
	else return 0;
}

int main() {

	ifstream myfile("lotto.txt");
	string citta;
	map<string, set<int>> mappa;
	typedef pair<string, set<int>> elemento;
	int n1, n2, n3, n4, n5;

	if (myfile.is_open()) {
		while (myfile >> citta >> n1 >> n2 >> n3 >> n4 >> n5) {
			set<int> numeri;
			numeri.insert(n1);
			numeri.insert(n2);
			numeri.insert(n3);
			numeri.insert(n4);
			numeri.insert(n5);
			mappa.insert(elemento(citta, numeri));
		}
	}
	else {
		cout << "errore";
	}
	for (map<string, set<int>>::iterator itMap = mappa.begin(); itMap != mappa.end(); itMap++) {
		cout << itMap->first << " ";
		for (set<int>::iterator itSet = itMap->second.begin(); itSet != itMap->second.end(); itSet++) {
			cout << *itSet << " ";
		}
		cout << endl;
	}

	cout << Find_terno(mappa, "Milano", 46, 84, 3);
	return 0;
}