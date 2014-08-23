/*
 * MergeSort.h
 *
 *  Created on: Aug 23, 2014
 *      Author: gdeforest
 */

#include <iostream>
using namespace std;

#ifndef MERGESORT_H_
#define MERGESORT_H_

class MergeSort {
	private:
	public:
		template <typename Type>
		static void sort(Type* unsorted, int length);
};

#endif /* MERGESORT_H_ */
