/*
 * MergeSort.cpp
 *
 *  Created on: Aug 23, 2014
 *      Author: gdeforest
 */

#include "include/MergeSort.h"

template <typename Type>
void MergeSort::sort(Type* unsorted, int length)
{
	for (int i = 0; i < length; i++) {
		cout << unsorted[i] << " ";
	}
}

template void MergeSort::sort(int*, int);
