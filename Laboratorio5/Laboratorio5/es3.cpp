
#include <iostream>
#include <cstdlib>

using namespace std;

#include "lstack.h"
#include "LStackTest.h"

using namespace std;


// Main routine 
int main(int argc, char** argv) {
	LStack<Item> S;
	Item temp1(1);
	Item temp2(2);
	Item temp3(3);
	S.push(temp1);
	S.push(temp2);
	S.push(temp3);

	Item it = S.pop();
	int risultato = it.key();

	while (S.length() > 0) {
		Item it = S.pop();
		risultato = risultato * it.key();

	}
	cout << risultato;
	return 0;
}