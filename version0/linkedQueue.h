#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "husky.h"

template <typename T> 
class linkedQueue {
public:
	linkedQueue() { 
		front = nullptr; 
		back = nullptr;
	}
	~linkedQueue() { makeEmpty(); }
	bool isEmpty() const { return front == nullptr; }
	const T& getFront() const;
	void enqueue(const T &x);
	T dequeue();
	void makeEmpty() { while (!isEmpty()) dequeue(); }
private:
	struct listNode {
		T element;
		listNode *link;
		listNode(const T &theElement, listNode *n = nullptr) :element(theElement), link(n) { }
	};
	listNode *front, *back;
};

template <typename T>
const T& linkedQueue<T>::getFront() const {
	if (isEmpty())
		throw " queue is empty";
	return front->element;
}

template < typename T>
void linkedQueue<T>::enqueue(const T &x) {
	if (isEmpty()) {
		front = new listNode(x);
		back = front;
	}
	else {
		back->link = new listNode(x);
		back = back->link;
	}
}

template <typename T>
T linkedQueue<T>::dequeue() {
	if (isEmpty())
		throw " queue is empty, cannot delete";
	T frontElement = getFront();
	listNode *delNode = front;
	front = front->link;
	delete delNode;
	return frontElement;
}

#endif // !LINKEDQUEUE_H
/*linkedQueue<int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);

	cout << myQ.getFront() << endl;
	cout << myQ.dequeue() << endl;
	cout << myQ.dequeue() << endl;
	cout << myQ.dequeue() << endl;*/