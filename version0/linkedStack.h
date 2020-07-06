#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "husky.h"

template <typename T> class linkedStack;

template <typename T>
class chainNode {
	friend class linkedStack<T>;
private:
	chainNode( const T &theData, chainNode *n=nullptr):data(theData),link(n) { }
	T data;
	chainNode<T> *link;
};

template <typename T> 
class linkedStack {
private:
	chainNode<T> *top;
public:
	linkedStack():top(nullptr) { }
	~linkedStack() { makeEmpty(); }
	bool isEmpty() const {	return top == nullptr; }
	T& Top() const;
	void Push(const T &e);
	void Pop();
	void makeEmpty();
};

template < typename T>
T& linkedStack<T>::Top() const {
	if (isEmpty())
		throw " stack is empty";
	return top->data;
}

template <typename T>
void linkedStack<T>::Push(const T &e) {
	top = new chainNode<T>(e, top);
}

template <typename T>
void linkedStack<T>::Pop() {
	if (isEmpty())
		throw " stack is empty, cannot delete";
	chainNode<T> *delNode = top;
	top = top->link;
	delete delNode;
}

template <typename T>
void linkedStack<T>::makeEmpty() {
	while (!isEmpty())
		Pop();
}

#endif // !LINKEDSTACK_H
/*linkedStack<int> s;
	s.Push(10);
	cout << s.Top() << endl;
	s.Push(20);
	cout << s.Top() << endl;
	s.Push(30);
	cout << s.Top() << endl;
	s.Push(40);
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;*/