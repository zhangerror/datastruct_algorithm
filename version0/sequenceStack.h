#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H
#include "husky.h"
#include <algorithm>

template <class T>
class mStack {
public:
	mStack(int stackCapacity = 10);
	~mStack() { delete[] stack; }
	bool isEmpty() const { return top == -1; }
	T& Top() const;
	void Pop();
	void Push(const T &item);
private:
	T *stack;		//用于创建动态数组
	int top;
	int capacity;
};

template <class T>
void changeSize(T* &a, const int oldSize, const int newSize) {
	if (newSize < 0)
		throw " new length must be >= 0";
	T *tmp = new T[newSize];
	int number = std::min(newSize, oldSize);
	std::copy(a, a + number, tmp);
	delete[] a;
	a = tmp;
}

template <class T>
mStack<T>::mStack(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)
		throw " stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
T& mStack<T>::Top() const {
	if (isEmpty())
		throw "stack is empty";
	return stack[top];
}

template <class T>
void mStack<T>::Pop() {
	if (isEmpty())
		throw " stack is empty";
	stack[top--].~T();
}

template <class T>
void mStack<T>::Push(const T &item) {
	if (top == capacity - 1) {
		changeSize(stack, capacity, capacity * 2);
		capacity *= 2;
	}
	stack[++top] = item;
}

#endif

/*mStack<int> st;
	st.Push(99);
	st.Push(22);
	st.Push(18);
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	st.Push(9);
	st.Push(2);
	st.Push(8);
	cout << st.Top() << endl;
	st.Push(59);
	st.Push(32);
	st.Push(18);
	st.Push(69);
	cout << st.Top() << endl;
	st.Push(92);
	st.Push(88);
	st.Push(29);
	st.Push(122);
	cout << st.Top() << endl;
	st.Push(118);
	cout << st.Top() << endl;*/