/*
 * MergeSort.cpp
 *
 *  Created on: Aug 23, 2014
 *      Author: gdeforest
 */

#include "include/MergeSort.h"

template <typename Type>
void MergeSort::sort(Type** unsorted, int length)
{
	int mid = length/2;
	// do an initial split
	Type** parts = split(*unsorted, mid);
	// recursively merge the two parts
	*unsorted = merge(parts[0], mid, parts[1], length - mid);
}

// virtually "splits" the array by assigning pointers
template <typename Type>
Type** MergeSort::split(Type* part, int mid)
{
	Type** parts = new Type*[2];
	parts[0] = part;
	parts[1] = part + mid;
	return parts;
}

template <typename Type>
Type* MergeSort::merge(Type* left, int leftLen, Type* right, int rightLen)
{
	int mid;
	Type** parts;

	// recursive cases
	if (leftLen > 1) {
		mid = leftLen/2;
		parts = split(left, mid);
		left = merge(parts[0], mid, parts[1], leftLen - mid);
	}

	if (rightLen > 1) {
		mid = rightLen/2;
		parts = split(right, mid);
		right = merge(parts[0], mid, parts[1], rightLen - mid);
	}

	// base case
	Type* result = new Type[leftLen + rightLen];
	int i1 = 0, i2 = 0, rIndex = 0;

	// while there are elements left from either set
	while (leftLen != i1 || rightLen != i2) {
		// if there are elements from both
		if (leftLen != i1 && rightLen != i2) {
			if (left[i1] < right[i2]) {
				result[rIndex++] = left[i1++];
			} else {
				result[rIndex++] = right[i2++];
			}
		} else if (leftLen != i1) {	//out of right elements
			result[rIndex++] = left[i1++];
		} else {	//implicitly rightLen != i2
			result[rIndex++] = right[i2++];
		}
	}

	return result;
}

template int** MergeSort::split(int*, int);
template int* MergeSort::merge(int*, int, int*, int);
template void MergeSort::sort(int**, int);
