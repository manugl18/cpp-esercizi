#include <cstdlib>
#include <iostream>
#include "min_heap.h"
#include "Item.h"
using namespace std;
int main() {
	int n1 = 4;
	int i = 0;
	int elem = 0;
	int costo = 0;
	PQ<int> priorityq(n1);

	priorityq.insert(4);
	priorityq.insert(3);
	priorityq.insert(2);
	priorityq.insert(6);

	while (i < n1 - 1) {
		int n1 = priorityq.getmin();
		int n2 = priorityq.getmin();
		elem = n1 + n2;
		cout << n1 << "+" << n2 << "=" << elem << endl;
		priorityq.insert(elem);
		costo += elem;
		i++;

	}
	cout << costo << endl;


	//esercizio 3

	const int k = 3;
	const int n = 4;

	int arr[k][n] = { {1,3,5,7}, {2,4,6,8}, {0,9,10,11} };
	int output[k * n];

	PQ<Item> priorityq2(k);
	priorityq2.insert(Item(arr[0][0], 0, 1));
	priorityq2.insert(Item(arr[1][0], 1, 1));
	priorityq2.insert(Item(arr[2][0], 2, 1));

	for (int i = 0; i < k * n; i++) {
		Item temp = priorityq2.getmin();
		output[i] = temp.getVal();
		int indice = temp.getIndice();
		int succ = temp.getIndiceSucc();
		if (succ < n) priorityq2.insert(Item(arr[indice][succ], indice, succ + 1));
	}
	for (int i = 0; i < k * n; i++) {
		cout << output[i] << " ";
	}

	return 0;
}