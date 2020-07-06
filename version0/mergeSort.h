#ifndef MERGESORT_H
#define MERGESORT_H
#include "husky.h"
#include <algorithm>

//原数据，排序后的数据，从哪一个开始，到哪一个结束，最后一个数据位置
template <class T>
void merge(T *initList, T *mergedList, const int len, const int m, const int n) {
	int i1, i2, iResult;
	for (i1 = len, i2 = m + 1, iResult = len; i1 <= m && i2 <= n; ++iResult) {
		if (initList[i1] <= initList[i2]) {
			mergedList[iResult] = initList[i1];
			++i1;
		}
		else {
			mergedList[iResult] = initList[i2];
			++i2;
		}
	}
	std::copy(initList + i1, initList + m + 1, mergedList + iResult);
	std::copy(initList + i2, initList + n + 1, mergedList + iResult);
}

template <class T>
void mergePass(T *initList, T *resultList, const int n, const int s) {
	int i;
	for (i = 1; i <= n - 2*s + 1; i += 2 * s)
		merge(initList, resultList, i, i + s - 1, i + 2*s - 1);
	if ((i + s - 1) < n)
		merge(initList, resultList, i, i + s - 1, n);
	else
		std::copy(initList + i, initList + n + 1, resultList + i);
}

template <class T> 
void mergeSort(T *a, const int n) {
	T *tmpList = new int[n + 1]; //tmpList[0]不用
	for (int i = 1; i < n; i *= 2) {
		mergePass(a, tmpList, n, i);
		i *= 2;
		mergePass(tmpList, a, n, i);
	}
	delete[] tmpList;
}

#endif // !MERGESORT_H
//mergeSort(list, sizeof(list) / sizeof(int)-1);
//display(list, 1, sizeof(list) / sizeof(int));
