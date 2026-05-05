#include <iostream>
#include <string>

#include "binary_tree2.h"
#include "ListTest.h"


int main() {

	BinaryTree<Item> myBT;
	Item it("pippo");
	myBT.AddItem(it);

	Item it2("topolino");
	myBT.AddItem(it2);

	Item it3("paperino");
	myBT.AddItem(it3);

	myBT.traverse();

	BinaryTree<Item> myBT2;
	Item it4("pippo");
	myBT2.AddItem(it4);

	Item it5("topolino");
	myBT2.AddItem(it5);

	Item it6("paperino");
	myBT2.AddItem(it6);
	cout << myBT.equal_tree_structure(myBT2.getRoot());
	return 0;


}