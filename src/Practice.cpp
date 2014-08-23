//============================================================================
// Name        : Practice.cpp
// Author      : Gabriel de Forest
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "DataStructures/include/HashTable.h"
#include "Algorithms/include/MergeSort.h"
#include "Algorithms/include/QuickSort.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void testHashTable()
{
	HashTable<int> table;
	for (char i = 48; i < 58; i++) {	//ascii 0
		string key(string("test ") + string(&i));
		table.set(key, i);

		int val = table.get(key);
		cout << key << ": " << val << endl;
	}
}

int main() {
	int test[] = {5, 3, 4, 1, 2};
	int test2[] = {5, 3, 4, 1, 2};
	MergeSort::sort(test, (int)(sizeof(test)/sizeof(int)));
	QuickSort::sort(test2, (int)(sizeof(test2)/sizeof(int)));
	return 0;
}
