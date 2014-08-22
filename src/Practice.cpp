//============================================================================
// Name        : Practice.cpp
// Author      : Gabriel de Forest
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "DataStructures/include/HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	HashTable<int> table;
	for (char i = 48; i < 58; i++) {	//ascii 0

		std::string key(std::string("test ") + std::string(&i));
		table.set(key, i);

		int val = table.get(key);
		std::cout << key << ": " << val << std::endl;
	}
	return 0;
}
