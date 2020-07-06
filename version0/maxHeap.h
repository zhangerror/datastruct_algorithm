#ifndef _MAXHEAP_H
#define _MAXHEAP_H
#include "husky.h"

template <typename T>
class maxHeap {
private:
	T *heapArray;
	int maxSize;
	int currentSize;
	void trickleDown(int index);
	void trickleUp(int index);
public:
	maxHeap(int mx = 10);
	virtual ~maxHeap() { delete[] heapArray; }
	bool isEmpty() { return currentSize == 0; }
	void Push(const T&);
	void Pop();
	const T& Top() const { return heapArray[0]; }
};

template <typename T>
maxHeap<T>::maxHeap(int mx) {
	if (mx < 1)
		throw "max size must be >= 1";
	maxSize = mx;
	currentSize = 0;
	heapArray = new T[maxSize];
}

template <typename T>
void maxHeap<T>::Push(const T &e) {
	if (currentSize == maxSize)
		throw "maxHeap is FULL";
	heapArray[currentSize] = e;
	trickleUp(currentSize++);
}

template <typename T>
void maxHeap<T>::trickleUp(int index) {
	int parent = (index - 1) / 2;
	T bottom = heapArray[index];
	while (index > 0 && heapArray[parent] < bottom) {
		heapArray[index] = heapArray[parent];
		index = parent;
		parent = (parent - 1) / 2;
	}
	heapArray[index] = bottom;
}

template <typename T>
void maxHeap<T>::Pop() {
	heapArray[0] = heapArray[--currentSize];
	trickleDown(0);
}

template <typename T>
void maxHeap<T>::trickleDown(int index) {
	int largeChild;
	T top = heapArray[index];
	while (index < currentSize / 2) {
		int leftChild = index * 2 + 1;
		int rightChild = leftChild + 1;
		if (rightChild < currentSize && heapArray[leftChild] < heapArray[rightChild])
			largeChild = rightChild;
		else largeChild = leftChild;
		if (top >= heapArray[largeChild])
			break;
		heapArray[index] = heapArray[largeChild];
		index = largeChild;
	}
	heapArray[index] = top;
}

#endif
/*maxHeap<int> h(100);
	cout << h.isEmpty() << endl;	//1
	h.Push(20);
	h.Push(30);
	h.Push(15);
	cout << h.Top() << endl;		//30
	h.Push(90);
	h.Push(35);
	cout << h.Top() << endl;		//90
	h.Pop();
	cout << h.Top() << endl;		//35*/