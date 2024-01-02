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
		n = 0;
		max = size;
	}

	~HashTable(){
		delete[] table;
	}

	int capacity() const{
		return max;
	}

	friend ostream&operator<<(ostream &out,const HashTable<V> &th){
		out << "HashTable [entries: " << th.entries() << ", capacity: "<< th.capacity() <<"]" << endl;
		
		out << "==============" << endl << endl;
		for(int i = 0;i < th.max;i++){

			out << "== Cubeta "<< i << " ==" << endl << endl << th.table[i] << endl << endl;
		}
		out << "==============" << endl;
		return out;
	}

	V operator[](string key){
		int pos = h(key);
                TableEntry<V> entry(key);
                int indice = table[pos].search(entry);

		if(indice == -1){
			throw runtime_error("Clave no encontrada");
		}else{
			return table[pos][indice].value;
		}
	}


	//Heredados
	
	void insert(string key, V value) override{
		int pos = h(key);
		TableEntry<V> entry(key,value);

		if(table[pos].search(entry) != -1){ // En caso de que ya exista
			throw runtime_error("Clave ya existe en la lista");
		}

		table[pos].prepend(entry);
		n++;
	}

	V search(string key) override {
        	int pos = h(key);
		TableEntry<V> entry(key);
		int indice = table[pos].search(entry);
					
		if(indice != -1){
			return table[pos][indice].value;
		}else{
			throw runtime_error("Clave no encontrada");
		}
        }

	V remove(string key) override {
  		int pos = h(key);
		TableEntry<V> entry(key);
		int indice = table[pos].search(entry);

		if(indice != -1){
			n--;
			return table[pos].remove(indice).value;
		}else{
			throw runtime_error("Clave no encontrada");
		}
        }

	int entries() const override{
		return n;
	}
};

#endif
