#include <list>
#include <iostream>
#include <queue>
using namespace std;

int main() {

    list<queue<int>> lista;

    queue<int> coda1;
    queue<int> coda2;
    queue<int> coda3;
    queue<int> coda4;

    coda1.push(30);
    coda1.push(12);
    coda1.push(1);
    coda1.push(203);
    coda1.push(10);

    coda2.push(7);

    coda3.push(14);
    coda3.push(29);
    coda3.push(45);
    coda3.push(9);

    coda4.push(2);
    coda4.push(13);
    coda4.push(8);

    lista.push_back(coda1);
    lista.push_back(coda2);
    lista.push_back(coda3);
    lista.push_back(coda4);

    list<queue<int>>::iterator end = lista.end();
    --end;
    for (list<queue<int>>::iterator it = lista.begin(); it != end; it++) {
        int c = it->front();
        it->pop();
        ++it; // vado alla prossima coda
        it->push(c);
        --it; // ritorno alla coda di prima perche poi il for incrementa.
    }

    for (list<queue<int>>::iterator it = lista.begin(); it != lista.end(); it++) {
        queue<int> c = *it;
        while (!c.empty()) {
            cout << c.front() << " " ;
            c.pop();
        }
        cout << endl;
    }
    return 0;
}