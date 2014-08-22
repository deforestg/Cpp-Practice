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

#define INITIAL_SIZE 10
#define MAXIMUM_LOAD_FACTOR 0.5f

template<typename Type>
struct bucket {
	std::string key;
	Type value;
};

template <typename Type>
class HashTable {
	private:
		bucket<Type>* container;
		int length;
		unsigned int hash(const std::string& key);
	public:
		HashTable();
		Type get(const std::string&);
		void set(const std::string& key, Type value);
};

#endif /* HASHTABLE_H_ */
