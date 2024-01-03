#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
	BSTree<TableEntry<V>>* tree;

    public:
	BSTreeDict(){
		tree = new BSTree<TableEntry<V>>;
	}

	~BSTreeDict(){
		delete tree;
	}

	friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs){
		return out << *bs.tree << endl;
	}

	V operator[](string key){
		return tree->search(TableEntry<V>(key)).value;
	}

	// Implementación metodos abstractos clase Dict<V>
	void insert(string key, V value){
		tree->insert(TableEntry<V>(key,value));
	}

	V search(string key){
		return tree->search(TableEntry<V>(key)).value;	
	}

	V remove(string key){
		V valor = tree->search(TableEntry<V>(key)).value;
		tree->remove(TableEntry<V>(key));
		return valor;
	}

	int entries() const override {
        	return tree->size();
	}

};

#endif
