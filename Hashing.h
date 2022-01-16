#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
	string key;
	T value;
	Node<T>*next;

	Node(string k , T val) {
		this->key = k;
		value = val;
		next = NULL;
	}


	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};


template<typename T>
class hashTable {
	Node<T>** table;
	int currentSize;
	int tableSize;

	int hashFuntion(string key) {
		int idx = 0;
		int p = 1;
		for (int i = 0 ; i < key.size() ; i++) {
			idx = (idx + key[i] * p) % tableSize;
			idx = idx % tableSize;
			p = (p * 27) % tableSize;
		}

		return idx;
	}

	void rehashing() {
		Node<T>**oldTable = table;
		int oldTableSize = tableSize;
		tableSize = 2 * tableSize;
		table = new Node<T>*[tableSize];

		currentSize = 0;

		for (int i = 0 ; i < tableSize ; i++) {
			table[i] = NULL;
		}


		for (int i = 0 ; i < oldTableSize ; i++) {
			Node<T>*temp = oldTable[i];
			while (temp != NULL) {
				insert(temp->key , temp->value);
				temp = temp->next;
			}
			if (oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}

		delete [] oldTable;
	}
public:
	hashTable(int ts = 7) {
		tableSize = ts;
		table = new Node<T>* [tableSize];
		for (int i = 0 ; i < tableSize ; i++) {
			table[i] = NULL;
		}
		currentSize = 0;
	}

	void insert(string key , T value) {
		int idx = hashFuntion(key);
		Node<T>*n = new Node<T>(key , value);
		// insert at head of the ll with  id=idx
		n->next = table[idx];
		table[idx] = n;
		currentSize++;

		float loadFactor = (float)currentSize / (float)tableSize;
		if (loadFactor > 0.7) {
			rehashing();
		}
	}


	void print() {
		for (int i = 0 ; i < tableSize ; i++) {
			cout << "Bucket " << i << " -> ";
			Node<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp->key << " -> ";
				temp = temp->next;
			}
			cout << endl;
		}
		cout << currentSize << endl;
	}


	T* search(string key) {

		int idx = hashFuntion(key);
		Node<T>* temp = table[idx];
		while (temp) {
			if (temp->key == key) {
				return &temp->value;
			}
			temp = temp->next;
		}

		return NULL;

	}

	void erase(string key) {
		int idx = hashFuntion(key);
		Node<T>*current = table[idx];
		Node<T>*prev;
		if (current->key == key) {
			table[idx] = current->next;
			delete current;
			return;
		}
		while (current->next != NULL and current->key != key) {
			prev = current;
			current = current->next;
		}
		if (current) {
			prev->next = current->next;
			delete current;
		}

		currentSize--;

	}

	T& operator [](string key) {
		T *p = search(key);
		if (p == NULL) {
			int garbage;
			insert(key , garbage);
			p = search(key);
		}

		return *p;
	}
};