#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "link.h"
#include "llist.h"
#include "listTest.h"

int main(int argc, char** argv) {

	LList<Item> L1;
	LList<Item> L2;
	LList<Item> L3;
	LList<Item> ordinata;
	L1.insert(Item(5));
	L1.insert(Item(1));
	L1.insert(Item(3));

	L2.insert(Item(1));
	L2.insert(Item(2));

	
	lprint<Item>(L2);

	return 0;
}