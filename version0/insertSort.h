#ifndef INSERTSORT_H
#define INSERTSORT_H

#include "husky.h"

template <class T>
void InsertionSort(T *a, const int n) {
	int in, out;
	for (out = 1; out < n; ++out) {
		T tmp = a[out];
		in = out;
		while (in > 0 && a[in - 1] > tmp) {
			a[in] = a[in - 1];
			--in;
		}
		a[in] = tmp;
	}
}

//a[0]仅用于排序，不用于保存原始数据
template <class T>
void insert(const T &e, T *a, int i) {
	a[0] = e;
	while (e < a[i]) {
		a[i + 1] = a[i];
		--i;
	}
	a[i + 1] = e;
}

template <class T>
void insertionSort_I(T *a, const int n) {
	for (int j = 2; j <= n; ++j) {
		T tmp = a[j];
		insert(tmp, a, j - 1);
	}
}

#endif // !INSERTSORT_H
/*
	InsertionSort(list, sizeof(list) / sizeof(int));
	insertionSort_I(list, sizeof(list) / sizeof(int) - 1);*/