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
		template <typename Type>
		static Type* merge(Type* left, int length1, Type* right, int length2);
		template <typename Type>
		static Type** split(Type* part, int mid);
	public:
		template <typename Type>
		static void sort(Type** unsorted, int length);
};

#endif /* MERGESORT_H_ */
