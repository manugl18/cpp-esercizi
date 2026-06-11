#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int, char* [])
{
	vector<int> v; // array dinamico. non va specificato il numero di elementi
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	int i = 7;

	// Stai dicendo al C++: "Ehi, usa l'algoritmo count partendo dall'inizio (v.begin) fino alla fine (v.end) per cercare il numero i".
	cout << i << " appears " << count(v.begin(), v.end(), i) << " times in v" << endl; 
	i = 2;
	cout << i << " appears " << count(v.begin(), v.end(), i) << " times in v" << endl;
	return 0;
}