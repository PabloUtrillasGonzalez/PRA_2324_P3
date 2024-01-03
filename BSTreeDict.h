#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {	// Clase intermediaria entre BSTree y Dict

    private:
	BSTree<TableEntry<V>>* tree;

    public:
	BSTreeDict(){ // Tree vacio
		tree = new BSTree<TableEntry<V>>;
	}

	~BSTreeDict(){	// Borramos dinamica
		delete tree;
	}

	friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs){ // Print
		return out << *bs.tree;
	}

	V operator[](string key){	// Devolvemos valor de la key
		return tree->search(TableEntry<V>(key)).value;
	}

	// Implementación metodos abstractos clase Dict<V>
	void insert(string key, V value){	//Insert clave, valor
		tree->insert(TableEntry<V>(key,value));
	}

	V search(string key){	//Busqueda del valor teniendo clave
		return tree->search(TableEntry<V>(key)).value;	
	}

	V remove(string key){	// Eliminamos mediante clave y devolvemos el valor que tenia
		V valor = tree->search(TableEntry<V>(key)).value;
		tree->remove(TableEntry<V>(key));
		return valor;
	}

	int entries() const override {	// Implementamos metodo entries
        	return tree->size();
	}

};

#endif
