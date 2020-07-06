#include "maxHeap.h"

//取出来，再放进去
void heapSort(int *a, const int n) {
	maxHeap<int> h(n);
	for (int i = 0; i < n; ++i) 
		h.Push(a[i]);
	for (int i = 0; i < n; ++i) {
		a[i] = h.Top();
		h.Pop();
	}
}

/*
	int a[] = { 3,5,2,6,7,1 };

	heapSort(a, sizeof(a) / sizeof(int));
	display(a, 0, sizeof(a) / sizeof(int));*/