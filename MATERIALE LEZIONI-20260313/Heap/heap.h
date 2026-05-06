#ifndef HEAP_H
#define HEAP_H

template <class Item>
void exch(Item& A, Item& B)
{
	Item t = A;
	A = B;
	B = t;
}

// =====================================
// Array-based Priority Queue
// =====================================

template <class Item>
class aPQ
{
private:
	Item* pq;
	int N;

public:
	aPQ(int maxN)
	{
		pq = new Item[maxN];
		N = 0;
	}

	~aPQ()
	{
		delete[] pq;
	}

	// Controlla se la coda è vuota
	int empty() const
	{
		return N == 0;
	}

	// Inserisce un elemento
	void insert(Item item)
	{
		pq[N++] = item;
	}

	// Estrae l'elemento con priorità massima - O(N)
	Item getmax()
	{
		int max = 0;

		for (int j = 1; j < N; j++)
		{
			// Richiede operatore < definito in Item
			if (pq[max] < pq[j])
			{
				max = j;
			}
		}

		// Sposta il massimo in fondo
		exch(pq[max], pq[N - 1]);

		// Restituisce l'ultimo elemento
		return pq[--N];
	}
};

// =====================================
// Heap Utilities
// =====================================

template <class Item>
//mette l’elemento in fondo all’heap, fixUp() lo fa salire finché l’heap resta valido
void fixUp(Item a[], int k)
{
	while (k > 1 && a[k / 2] < a[k])
	{
		exch(a[k], a[k / 2]);
		k = k / 2;
	}
}

template <class Item>
//fa scendere il primo elemento poiche dopo getmax() la rdice e ultimo elemento vengono scambiati
void fixDown(Item a[], int k, int N)
{
	while (2 * k <= N) // figlio sinistro = 2K. Se non esiste un figlio sinistro non ce neanche un figlio destro
	{
		int j = 2 * k;
		if (j < N && a[j] < a[j + 1]) // se j < n significa che ce anche un figlio destro
		{
			j++;
		}
		if (!(a[k] < a[j]))
		{
			break;
		}
		exch(a[k], a[j]);
		k = j;
	}
}

// =====================================
// Heap-based Priority Queue
// =====================================

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

	// Estrae il massimo - O(log N)
	Item getmax()
	{
		exch(pq[1], pq[N]);

		fixDown(pq, 1, N - 1);

		return pq[N--];
	}
};

// =====================================
// Heap Sort tramite Priority Queue
// =====================================

template <class Item>
void PQsort(Item a[], int l, int r)
{
	PQ<Item> pq(r - l + 1);

	for (int k = l; k <= r; k++) // prendo gli elementi dell'array (non ordinato) e li metto nell heap
	{
		pq.insert(a[k]);
	}

	for (int k = r; k >= l; k--) // estraggo max dall heap e lo metto in fondo all array cosi l array sarà crescente
	{
		a[k] = pq.getmax();
	}
}

#endif