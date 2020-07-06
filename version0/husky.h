#ifndef HUSKY_H
#define HUSKY_H

#include <iostream>

void BubbleSort(int list[], const int n);
void selectSort(int *list, const int n);
int binarySearch(int *a, const int x, const int n);
int binarySort_R(int *a, const int x, const int left, const int right);
void permutations(char *p, const int k, const int m);
int maxDigit(int data[], int n);
void radixSort(int data[], int n);
void heapSort(int *a, const int n);

template <typename T>
void display(const T list[], const int m,const int n) {
	for (int i = m; i < n; ++i)
		std::cout << list[i] << std::ends;
	std::cout << std::endl;
}

#endif // !HUSKY_H
