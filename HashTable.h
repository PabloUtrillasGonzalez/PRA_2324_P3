#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../Prac02/PRA_2324_P1/ListLinked.h"  //Modificado

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
	int n;
	int max;
	ListLinked<TableEntry<V>>* table;

	// Calcula el hash de key, suma valores ascii numericos de kis caracteres de la clave y el tamaño de la tabla hash
	int h(string key){
		int reslt = 0;
		for(int i = 0; i < key.length(); i++){
			reslt += int(key.at(i));
		}
		return (reslt%max);
	}

    public:
	HashTable(int size){
		table = new ListLinked<TableEntry<V>>[size];
		n = size;
		max = size;
	}

	~HashTable(){
		delete[] table;
	}

	int capacity(){
		return max;
	}

	friend ostream&operator<<(ostream &out,const HashTable<V> &th){
		for(auto a : th){
			out << a << endl;
		}
		return out;
	}

	V operator[](string key){
		int val;
		val = h(key);
		if(val == 0){
			throw runtime_error(key);
		}else{
			return val;
		}
	}
};

#endif
