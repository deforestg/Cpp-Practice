/*
 * QuickSort.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: gdeforest
 */

#include "include/QuickSort.h"
#include <stdlib.h>

/**
 * public convenience sort method
 * @param Type** arr
 * @param int length
 */
template <typename Type>
void QuickSort::sort(Type** arr, int length)
{
	sort(arr, 0, length-1);
}

/**
 * internal sort method
 * @param Type** arr
 * @param int left
 * @param int right
 */
template <typename Type>
void QuickSort::sort(Type** arr, int left, int right)
{
	if (left < right) {
		int p = partition(*arr, left, right);
		sort(arr, left, p - 1);
		sort(arr, p + 1, right);
	}
}

/**
 * use median of three to choose partition
 * @param Type* arr
 * @param int left
 * @param int right
 * @return final swap index
 */
template <typename Type>
int QuickSort::partition(Type* arr, int left, int right)
{
	int pivot = pickIndex(arr, left, right);

	Type pivotVal = arr[pivot];

	swap(arr, pivot, right);
	int storeIndex = left;

	for (int i = left; i < right; i++) {
		if (arr[i] < pivotVal) {
			swap(arr, storeIndex, i);
			storeIndex++;
		}
	}

	swap(arr, storeIndex, right);

	return storeIndex;
}

/**
 * use median of three to choose partition
 * @param Type* arr
 * @param int left
 * @param int right
 * @return initial swap index
 */
template <typename Type>
int QuickSort::pickIndex(Type* arr, int left, int right)
{
	int mid = (left + right)/2;

	// always does exactly 2 comparisons
	if (arr[left] > arr[mid]) {
		if (arr[right] > arr[left]) {
			return left;
		} else if (arr[right] > arr[mid]) {
			return right;
		} else {
			return mid;
		}
	} else {
		if (arr[right] > arr[mid]) {
			return mid;
		} else if (arr[right] > arr[left]) {
			return right;
		} else {
			return left;
		}
	}
}

/**
 * swap two elements
 * @param Type* arr
 * @param int index1
 * @param int index2
 */
template <typename Type>
void QuickSort::swap(Type* arr, int index1, int index2)
{
	Type temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

template void QuickSort::sort(int**, int);
template void QuickSort::sort(int**, int, int);
template int QuickSort::partition(int*, int, int);
template int QuickSort::pickIndex(int*, int, int);
template void QuickSort::swap(int*, int, int);
