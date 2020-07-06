#ifndef RLIST_H
#define RLIST_H
#include "husky.h"

template <typename T> class list;
template <typename T> class listIterator;

template <typename T>
class listNode {
	friend class list<T>;
	friend class listIterator<T>;
private:
	T data;
	listNode* link;
	listNode(const T element);
	listNode() {}
};

template <typename T>
class list {
	friend class listIterator<T>;
public:
	list() { 
		first = new listNode<T>;
		first->link = first;
	}
	void Insert(const T k);
	void show() const;
	void Delete(const T k);
private:
	listNode<T> * first;
};

template <typename T>
class listIterator {
public:
	listIterator(const list<T> &l) :list(l), current(l.first->link) {}
	bool NotNull();
	bool NextNotNull();
	T* First();
	T* Next();
private:
	const list<T> &list;
	listNode<T> *current;
};

template <typename T>
listNode<T>::listNode(const T element) {
	data = element;
	link = 0;
}

template <typename T>
void list<T>::Insert(const T k) {
	listNode<T> *newNode = new listNode<T>(k);
	newNode->link = first->link;
	first->link = newNode;
}

template <typename T>
void list<T>::show() const {
	for (listNode<T> *current = first; current; current = current->link) {
		std::cout << current->data;
		if (current->link)
			std::cout << " -> ";
	}
	std::cout << std::endl;
}

template <typename T>
void list<T>::Delete(const T k) {
	listNode<T> *previous = first;
	listNode<T> *current;
	for (current = first->link;
		current!=first && current->data != k; 
		previous = current, current = current->link) {}
	if (current!=first) {
		previous->link = current->link;
		delete current;
	}
}

template <typename T>
bool listIterator<T>::NotNull() {
	if (current != list.first)
		return true;
	return false;
}

template <typename T>
bool listIterator<T>::NextNotNull() {
	if (list.first != current->link)
		return true;
	return false;
}

template <typename T>
T* listIterator<T>::First() {
	if (list.first != current)
		return &current->data;
	return 0;
}

template <typename T>
T* listIterator<T>::Next() {
	current = current->link;
	if (current == list.first) 		
		current = current->link;
	return &current->data;
}

#endif

/*
list<int> li;
	li.Insert(5);
	li.Insert(4);
	li.Insert(3);
	li.Insert(2);
	li.Insert(1);

	listIterator<int> il(li);
	if (il.NotNull()) {
		cout << *il.First();
		while (il.NextNotNull())
			cout << " -> " << *il.Next();
		cout << endl;
	}
	listIterator<int> iter(li);
	cout << *iter.First() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;*/