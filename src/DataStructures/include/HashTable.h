/*
 * HashTable.h
 *
 *  Created on: Aug 19, 2014
 *      Author: deforestg
 */

#include <iostream>
using namespace std;

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define INITIAL_SIZE 100
#define MAXIMUM_LOAD_FACTOR 0.5f

template<class T> struct bucket {
	std::string key;
    T value;
};

template <class Type> class HashTable {
	private:
		bucket<Type>* container;
		int length;
		int hash(std::string key);
	public:
		HashTable();
		Type get(std::string key);
		void set(std::string key, Type value);
};

#endif /* HASHTABLE_H_ */
