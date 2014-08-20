/*
 * HashTable.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: deforestg
 */

#include "HashTable.h"

HashTable<class Type>::HashTable()
{
	container = new bucket<Type>[INITIAL_SIZE];
	length = INITIAL_SIZE;
}

Type HashTable<class Type>::get(std::string key)
{

}


void HashTable<class Type>::set(std::string key, Type value)
{

}

int HashTable<class Type>::hash(std::string)
{

}
