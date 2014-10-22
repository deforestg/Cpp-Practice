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

void generateRandomData(int* arr, int len)
{
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % len;
	}
}

void copyData(int* src, int* dest, int len)
{
	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
}

void testSorts(int testLen)
{
    timeval time;
    double current, start;
    int *test, *test2, *test3;
    test = new int[testLen];
    test2 = new int[testLen];
    test3 = new int[testLen];

    generateRandomData(test, testLen);
    copyData(test, test2, testLen);
    copyData(test, test3, testLen);

    // my mergesort
    gettimeofday(&time, NULL);
    start = time.tv_sec + (time.tv_usec/1000000.0);

	MergeSort::sort(&test, testLen);

    gettimeofday(&time, NULL);
    current = time.tv_sec + (time.tv_usec/1000000.0);
	std::cout << "Merge sorted " << testLen << " items in " << current - start << " seconds" << endl;

	// my quicksort
    gettimeofday(&time, NULL);
    start = time.tv_sec + (time.tv_usec/1000000.0);

	QuickSort::sort(&test2, testLen);

    gettimeofday(&time, NULL);
    current = time.tv_sec + (time.tv_usec/1000000.0);
	std::cout << "Quick sorted " << testLen << " items in " << current - start << " seconds" << endl;

	// cpp sort
	std::vector<int> myvector (test3, test3+testLen);

    gettimeofday(&time, NULL);
    start = time.tv_sec + (time.tv_usec/1000000.0);

	std::sort(myvector.begin(), myvector.end());

    gettimeofday(&time, NULL);
    current = time.tv_sec + (time.tv_usec/1000000.0);
	std::cout << "C++ sorted " << testLen << " items in " << current - start << " seconds" << endl;
}

int main() {
	srand (time(NULL));

	testSorts(1000000);

	return 0;
}
