/*
 * QuickSort.h
 *
 *  Created on: Oct 21, 2014
 *      Author: gdeforest
 */

#include <iostream>

using namespace std;

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort {
	private:
		template <typename Type>
		static void sort(Type** arr, int left, int right);
		template <typename Type>
		static int partition(Type* arr, int left, int right);
		template <typename Type>
		static int pickIndex(Type* arr, int left, int right);
		template <typename Type>
		static void swap(Type* arr, int index1, int index2);
	public:
		template <typename Type>
		static void sort(Type** arr, int length);
};

#endif /* QUICKSORT_H_ */
