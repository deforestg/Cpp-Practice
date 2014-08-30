/*
 * QuickSort.h
 *
 *  Created on: Aug 23, 2014
 *      Author: gdeforest
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort {
	private:
		template <typename Type>
		static int partition(Type** part, int length);
	public:
		template <typename Type>
		static void sort(Type** unsorted, int length);
};

#endif /* QUICKSORT_H_ */
