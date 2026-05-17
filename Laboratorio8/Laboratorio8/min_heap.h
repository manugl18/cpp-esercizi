#pragma once
template <class Item>
void exch(Item& A, Item& B)
{
	Item t = A;
	A = B;
	B = t;
}
// ---------------------Heap Utilities----------------------------

template <class Item>
//mette l’elemento in fondo all’heap, fixUp() lo fa salire finché l’heap resta valido
void fixUp(Item a[], int k)
{
	while (k > 1 && a[k / 2] > a[k])
	{
		exch(a[k], a[k / 2]);
		k = k / 2;
	}
}

template <class Item>
//fa scendere il primo elemento poiche dopo getmin() la radice e ultimo elemento vengono scambiati
void fixDown(Item a[], int k, int N)
{
	while (2 * k <= N) // figlio sinistro = 2K. Se non esiste un figlio sinistro non ce neanche un figlio destro
	{
		int j = 2 * k;
		if (j < N && a[j] > a[j + 1]) // se j < n significa che ce anche un figlio destro
		{
			j++;
		}
		if (!(a[k] > a[j]))
		{
			break;
		}
		exch(a[k], a[j]);
		k = j;
	}
}

template <class Item>
class PQ
{
private:
	Item* pq;
	int N;

public:
	PQ(int maxN)
	{
		pq = new Item[maxN + 1];
		N = 0;
	}

	~PQ()
	{
		delete[] pq;
	}

	int empty() const
	{
		return N == 0;
	}

	void insert(Item item)
	{
		pq[++N] = item;
		fixUp(pq, N);
	}

	// Estrae il minimo - O(log N)
	Item getmin()
	{
		exch(pq[1], pq[N]);

		fixDown(pq, 1, N - 1);

		return pq[N--];
	}
};