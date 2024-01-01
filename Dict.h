#ifndef DICT_H
#define DICT_H
#include <string>

template <typename V> 
class Dict {
    public:
        // ... aquí los métodos virtuales puros
	void insert(std::string key, V value);
	V search(std::string key);
	V remove(std::string key);
	int entries();
};

#endif
