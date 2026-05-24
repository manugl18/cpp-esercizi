#pragma once

//#include "symbol_table_item.h"

#include <iostream>
using namespace std;

#include <stdlib.h>
#include "llist.h"
#include "symbol_table_item.h"
// classe template per la realizzazione di un albero binario di ricerca
template <class Item, class Key> // ricoda: ANZI CHE KEY si usa o int o string. L'etichetta ITEM non centra nulla con la classe ITEM
class BST
{
private:
	// definizione di una struttura dati per rappresentare i nodi dell'albero
	struct node
	{
		Item item; node* l, * r;
		node(Item x)
		{
			item = x; l = 0; r = 0;
		}
	};
	typedef node* link;
	link head;
	Item nullItem;


	void mergeR(LList<Item>& lista, link a, link b)
	{
		// inserisco tutti gli elementi del primo albero
		for (int i = 0; i < tree_size(a); i++)
		{
			lista.append(selectR(a, i));
		}

		// elaboro il secondo albero
		for (int j = 0; j < tree_size(b); j++)
		{
			Item element = selectR(b, j);

			bool trovato = false;

			// cerco nella lista
			for (lista.moveToStart();lista.currPos() < lista.length();lista.next())
			{
				Item curr = lista.getValue();

				// stessa chiave -> concateno stringhe
				if (curr.key() == element.key())
				{
					Item nuovo(curr.key(),curr.getinfo() + element.getinfo());

					lista.remove();
					lista.insert(nuovo);

					trovato = true;
					break;
				}

				// posizione corretta ordinata
				if (element.key() < curr.key())
				{
					lista.insert(element);
					trovato = true;
					break;
				}
			}

			// se non inserito, va in fondo
			if (!trovato)
			{
				lista.append(element);
			}
		}
	}
	// ricerca di un elemento data una chiave in ingresso
	// restituisce, se presente, il primo elemento trovato nell'albero con la chiave cercata
	Item searchR(link h, Key v)
	{
		if (h == 0) return nullItem;
		Key t = h->item.key();
		if (v == t) return h->item;
		if (v < t) return searchR(h->l, v);
		else return searchR(h->r, v);
	}

	// inserimento di un elemento nell'albero binario di ricerca
	void insertR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (x.key() < h->item.key())
			insertR(h->l, x);
		else insertR(h->r, x);
	}

	void showR(link h, ostream& os)
	{
		if (h == 0) return;

		h->item.show(os);
		showR(h->l, os);
		showR(h->r, os);
	}

	void showPostOrder(link h, ostream& os) {
		if (h == 0) return;

		showPostOrder(h->l, os);
		showPostOrder(h->r, os);
		h->item.show(os);
	}
	void rotR(link& h)
	{
		link x = h->l; h->l = x->r; x->r = h; h = x;
	}
	void rotL(link& h)
	{
		link x = h->r; h->r = x->l; x->l = h; h = x;
	}

	// inserimento in radice
	void insert_rootR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (x.key() < h->item.key())
		{
			insert_rootR(h->l, x); rotR(h);
		}
		else { insert_rootR(h->r, x); rotL(h); }
	}

	// restituisce il k-mo elemento con chiave minore dell'albero. K = 0 -> elemento con chiave piu piccola, k = 1 -> secondo elemento con chiave piu piccola ...
	Item selectR(link h, int k)
	{
		if (h == 0) return nullItem;
		int t = tree_size(h->l);
		if (t > k) return selectR(h->l, k);
		if (t < k) return selectR(h->r, k - t - 1); //-t → togli i nodi a sinistra; -1 → togli la radice
		return h->item;
	}

	// partizionamento: porta in radice il k-mo elemento con chiave minore
	void partR(link& h, int k)
	{
		int t = tree_size(h->l);
		if (t > k)
		{
			partR(h->l, k); rotR(h);
		}
		if (t < k)
		{
			partR(h->r, k - t - 1); rotL(h);
		}
	}

	// fonde due alberi binari di ricerca in cui il secondo (b) contiene elementi con chiavi maggiori delle chiavi del primo albero (a)
	// restituisce il nodo radice dell'albero risultante dalla fusione di a e b
	link joinLR(link a, link b)
	{
		if (b == 0) return a;
		partR(b, 0); b->l = a;
		return b;
	}

	// elimina, se presente, il primo elemento nell'albero con chiave v
	void removeR(link& h, Key v)
	{
		if (h == 0) return;
		Key w = h->item.key();
		if (v < w) removeR(h->l, v);
		if (w < v) removeR(h->r, v);
		if (v == w)
		{
			link t = h;
			h = joinLR(h->l, h->r); delete t;
		}
	}

	// fonde due alberi binari di ricerca generici
	link joinR(link a, link b)
	{
		if (b == 0) return a;
		if (a == 0) return b;
		insert_rootR(b, a->item);
		b->l = joinR(a->l, b->l);
		b->r = joinR(a->r, b->r);
		delete a; return b;
	}

	void rand_insertR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (rand() < RAND_MAX / (1 + tree_size(h)))
		{
			insert_rootR(h, x); return;
		}
		if (x.key() < h->item.key())
			rand_insertR(h->l, x);
		else rand_insertR(h->r, x);
	}

	// bilanciamento di un albero binario di ricerca
	void balanceR(link& h)
	{
		int size;
		size = tree_size(h);

		if (size < 2) return;
		partR(h, size / 2);
		balanceR(h->l);
		balanceR(h->r);
	}

	/*
	int height(link h)
	{
		if (h == 0) return -1;
		int u = height(h->l), v = height(h->r);
		if (u > v) return u + 1; else return v + 1;
	}
	*/
public:
	BST()
	{
		head = 0;
	}

	int tree_size(link tree) {
		if (!tree) return 0;
		return 1 + tree_size(tree->r) + tree_size(tree->l);
	}
	link getRoot() const {
		return head;
	}
	Item search(Key v)
	{
		return searchR(head, v);
	}
	void insert(Item x)
	{
		insertR(head, x);
	}
	void show(ostream& os)
	{
		showR(head, os);
	}
	void show_PO(ostream& os)
	{
		showPostOrder(head, os);
	}
	void insert_root(Item item)
	{
		insert_rootR(head, item);
	}
	Item select(int k)
	{
		return selectR(head, k);
	}
	void remove(Item x)
	{
		removeR(head, x.key());
	}
	void join(BST<Item, Key>& b)
	{
		head = joinR(head, b.head);
	}
	void rand_insert(Item x)
	{
		rand_insertR(head, x);
	}
	void balance()
	{
		balanceR(head);
	}
	void merge(LList<Item> &lista, link b) {
		mergeR(lista, head, b);
	}

	/*int tree_height()
	{
		return height(head);
	}*/
};

