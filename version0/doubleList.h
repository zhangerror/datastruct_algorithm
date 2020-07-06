#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "husky.h"

template <typename T>
class DList;

template <typename T>
class DListNode {
	friend class DList<T>;
public:
	T data;
	DListNode<T> *llink, *rlink;
};

template <typename T>
class DList {
public:
	DList() {
		first = new DListNode<T>();
		first->llink = first->rlink = first;
	}
	void Insert(DListNode<T> *p, DListNode<T> *x);
	void Delete(DListNode<T> *);

private:
	DListNode<T> *first;
};

template <typename T>
void DList<T>::Insert(DListNode<T> *p, DListNode<T> *x) {
	//p²åÔÚxÖ®ºó
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}

template <typename T> 
void DList<T>::Delete(DListNode<T> *x) {
	if (x == first)
		std::cerr << " deletion of head node not permitted" << std::endl;
	else {
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
	}
}

#endif

/*DListNode<int> n1, n2, n3, n4;
	n1.data = 10;
	n2.data = 20;
	n3.data = 30;
	n4.data = 40;

	DList<int> dl;
	dl.Insert(&n1, dl.first);
	dl.Insert(&n2, dl.first);
	dl.Insert(&n3, dl.first);
	dl.Insert(&n4, dl.first);
	cout << dl.first->llink->data << endl;
	cout << dl.first->rlink->data << endl;
	dl.Delete(&n4);
	cout << dl.first->llink->data << endl;
	cout << dl.first->rlink->data << endl;*/