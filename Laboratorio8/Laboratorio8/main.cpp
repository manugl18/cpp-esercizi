#include <cstdlib>
#include <iostream>
#include "min_heap.h"

using namespace std;
int main() {
	int n = 4;
	int i = 0;
	int elem = 0;
	int costo = 0;
	PQ<int> priorityq(n);

	priorityq.insert(4);
	priorityq.insert(3);
	priorityq.insert(2);
	priorityq.insert(6);

	while (i < n - 1) {
		int n1 = priorityq.getmin();
		int n2 = priorityq.getmin();
		elem = n1 + n2;
		cout << n1 << "+" << n2 << "=" << elem << endl;
		priorityq.insert(elem);
		costo += elem;
		i++;

	}
	cout << costo;
	return 0;
}