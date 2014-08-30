//============================================================================
// Name        : Practice.cpp
// Author      : Gabriel de Forest
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "DataStructures/include/HashTable.h"
#include "Algorithms/include/MergeSort.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <algorithm>
#include <vector>

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

void testCppSort(int testLen)
{
	int* test = new int[testLen];
	for (int i = 0; i < testLen; i++) {
		test[i] = rand() % testLen;
	}
	std::vector<int> myvector (test, test+testLen);

    timeval time;
    gettimeofday(&time, NULL);
    double current, start = time.tv_sec + (time.tv_usec/1000000.0);

	std::sort (myvector.begin(), myvector.end());

    gettimeofday(&time, NULL);
    current = time.tv_sec + (time.tv_usec/1000000.0);
	std::cout << "C++ sorted " << testLen << " items in " << current - start << " seconds" << endl;
}

void testMergeSort(int testLen)
{
	int* test = new int[testLen];
	for (int i = 0; i < testLen; i++) {
		test[i] = rand() % testLen;
	}

    timeval time;
    gettimeofday(&time, NULL);
    double current, start = time.tv_sec + (time.tv_usec/1000000.0);

	MergeSort::sort(&test, testLen);

    gettimeofday(&time, NULL);
    current = time.tv_sec + (time.tv_usec/1000000.0);
	std::cout << "Merge sorted " << testLen << " items in " << current - start << " seconds" << endl;
}

int main() {
	srand (time(NULL));

	testMergeSort(1000000);
	testCppSort(1000000);

	return 0;
}
