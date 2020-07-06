#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "husky.h"

template <class T>
void quickSort(T *a, const int left, const int right) {
	if (left < right) {
		//选第一个元素为枢轴
		int i = left;
		int j = right + 1;
		int pivot = a[left];
		//划分
		do {
			do ++i; while (a[i] < pivot);
			do --j; while (a[j] > pivot);
			if (i < j)
				std::swap(a[i], a[j]);
		} while (i < j);
		std::swap(a[left], a[j]);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

#endif // !QUICKSORT_H

//quickSort(list, 0, sizeof(list) / sizeof(int)-2);