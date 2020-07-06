#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
#include "husky.h"

template <typename T>
class Queue {
public :
	Queue(int queueCapacity = 10);
	~Queue() { delete[] queue; }
	bool isEmpty() const { return front == rear; }
	T& Front() const;
	T& Rear() const;
	void Push(const T &item);
	void Pop();
	void changeSize(const int oldSize, const int newSize);
private:
	T *queue;
	int front;		//����frontΪ��
	int rear;
	int capacity;
};

template <typename T>
void Queue<T>::changeSize( const int oldSize, const int newSize) {
	T *tmp = new T[newSize];
	int start = (front + 1) % capacity;
	if (start < 2) //û�л�ת������δ��תʱfrontһ���ڵ�0��λ��
		std::copy(queue + start, queue + capacity-1, tmp);
	else {
		std::copy(queue + start, queue + capacity, tmp);
		std::copy(queue, queue + rear + 1, tmp + capacity - start);
	}
	front = newSize - 1;
	rear = oldSize - 2;		//����ʱԭ����front��rear��һ��λ�ò�ͬrearһ���Ƶ�tmp����odeSize-1Ϊ��
	delete[] queue;
	queue = tmp;
}

template <typename T>
Queue<T>::Queue(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)
		throw "queue capacity must be > 0";
	queue = new T[capacity];
	front = 0;
	rear = 0;
}

template <typename T>
inline T& Queue<T>::Front() const {
	if (isEmpty())
		throw " queue is empty, no front element.";
	return queue[(front + 1) % capacity];
}

template <typename T>
inline T& Queue<T>::Rear() const {
	if (isEmpty())
		throw " queue is empty, no rear element.";
	return queue[rear];
}

template <typename T>
void Queue<T>::Pop() {
	if (isEmpty())
		throw "queue is empty, connot delete.";
	front = (front + 1) % capacity;
	queue[front].~T();
}

template <typename T>
void Queue<T>::Push(const T &item) {
	if ((rear + 1) % capacity == front)
		changeSize(capacity, capacity * 2);
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

#endif