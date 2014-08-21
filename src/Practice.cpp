//============================================================================
// Name        : Practice.cpp
// Author      : Gabriel de Forest
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "DataStructures/include/HashTable.h"
#include <iostream>
using namespace std;

int main() {
	HashTable<int> table;
	table.set("test", 1);
	table.set("test2", 2);
	std::cout << table.get("test1") << std::endl;
	std::cout << table.get("test2") << std::endl;
	return 0;
}
