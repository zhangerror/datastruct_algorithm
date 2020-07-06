#ifndef LIST_H
#define LIST_H
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
};

template <typename T>
class list {
	friend class listIterator<T>;
public:
	list() { first = 0; }
	void Insert(const T k);
	void show() const;
	void Delete(const T k);
	void Inverse();
	void Concatenate(list<T> b);
private:
	listNode<T> * first;
};

template <typename T> 
class listIterator {
public:
	listIterator(const list<T> &l):list(l), current(l.first) {}
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
	newNode->link = first;
	first = newNode;
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
	listNode<T> *previous = 0;
	listNode<T> *current = 0;
	for (current = first; current && current->data != k; previous = current, current = current->link) {}
	if (current) {
		if (previous)
			previous->link = current->link;
		else
			first = first->link;
		delete current;
	}
}

template <typename T> 
void list<T>::Inverse() {
	listNode<T> *p = first, *q = 0; //链表的开头和结尾
	while (p) {
		listNode<T> *r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}

template <typename T> 
void list<T>::Concatenate(list<T> b) {
	if (!first) {
		first = b.first;
		return;
	}
	if (b.first) {
		listNode<T> *p;
		for (p = first; p->link; p = p->link);	//找最后一个节点
		p->link = b.first;
	}
}

template <typename T> 
bool listIterator<T>::NotNull() {
	if (current)
		return true;
	return false;
}

template <typename T>
bool listIterator<T>::NextNotNull() {
	if (current && current->link)
		return true;
	return false;
}

template <typename T>
T* listIterator<T>::First() {
	if (list.first)
		return &list.first->data;
	return 0;
}

template <typename T>
T* listIterator<T>::Next() {
	if (current) {
		current = current->link;
		return &current->data;
	}
	return 0;
}

#endif
/*
list<int> iList;
	iList.Insert(3);
	iList.show();
	iList.Insert(4);
	iList.show();
	iList.Insert(5);
	iList.show();
	iList.Inverse();
	iList.show();

	iList.Delete(4);
	iList.show();

	list<int> iL;
	iL.Insert(2);
	iL.Insert(1);
	iL.Concatenate(iList);
	iL.show();

	listIterator<int> li(iL);
	if (li.NotNull()) {
		cout << *li.First();
		while (li.NextNotNull())
			cout << " -> " << *li.Next();
		cout << endl;
	}*/