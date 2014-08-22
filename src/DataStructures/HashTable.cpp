/*
 * HashTable.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: deforestg
 */

#include "include/HashTable.h"

template <typename Type>
HashTable<Type>::HashTable()
{
	container = new bucket<Type>[INITIAL_SIZE];
	length = INITIAL_SIZE;
}

template <typename Type>
Type HashTable<Type>::get(const std::string& key)
{
	unsigned int index = hash(key);
	if (container[index].key.compare(key) == 0) {
		return container[index].value;
	}

	int stopIndex = index++;
	while (stopIndex != index && container[index].value != NULL) {
		if (container[index].key.compare(key) == 0) {
			return container[index].value;
		}

		if (++index >= length) {	//loop around
			index = 0;
		}
	}

	return 0;
}


template <typename Type>
void HashTable<Type>::set(const std::string& key, Type value)
{
	unsigned int index = hash(key);

	int stopIndex = index - 1;
	while (stopIndex != index && container[index].value != NULL) {
		if (++index >= length) {	//loop around
			index = 0;
		}
	}

	bucket<Type> contents;
	contents.key = key;
	contents.value = value;
	container[index] = contents;
}

template <typename Type> unsigned int HashTable<Type>::hash(const std::string& s)
{
	unsigned h = 86969;
	for (int i = 0; i < s.length(); i++) {
		h = (h * s[i]);
	}
	return h % length;
}

template struct bucket<int>;
template class HashTable<int>;
