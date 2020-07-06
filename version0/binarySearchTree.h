#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "husky.h"

enum Boolean { False, True};

template <typename T>
class element {
public:
	T key;
};

template <typename T> class BST;

template <typename T>
class BSTNode {
	friend class BST<T>;
private:
	element<T> data;
	BSTNode *leftChild;
	BSTNode *rightChild;
	void display(int i);
};

template <typename T>
class BST {
public:
	BST(BSTNode<T> *init=nullptr):root(init) { }
	Boolean Insert(const element<T> &x);
	BSTNode<T>* search(const element<T> &x);
	BSTNode<T>* search(BSTNode<T>*, const element<T>&);
	BSTNode<T>* IterSearch(const element<T>&);
	void display() const;
private:
	BSTNode<T> *root;
};

template <typename T>
void BSTNode<T>::display(int i) {
	std::cout << "Position: " << i << ", data.key= " << data.key << std::endl;
	if (leftChild) leftChild->display(i * 2);
	if (rightChild) rightChild->display(i * 2 + 1);
}

template <typename T>
Boolean BST<T>::Insert(const element<T> &x) {
	BSTNode<T> *p = root;
	BSTNode<T> *q = nullptr;		//当前正在操作的节点的父节点（q指向p的父节点）

	//找合适位置
	while (p) {
		q = p;
		if (x.key == p->data.key)
			return False;
		else if (x.key < p->data.key)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	//找到q
	p = new BSTNode<T>;
	p->leftChild = nullptr;
	p->rightChild = nullptr;
	p->data = x;
	if (!root)
		root = p;
	else if (x.key < q->data.key)
		q->leftChild = p;
	else
		q->rightChild = p;
	return True;
}

template <typename T>
void BST<T>::display() const{
	if (root)
		root->display(1);
	else
		std::cout << " null tree";
}

template <typename T>
BSTNode<T>* BST<T>::search(const element<T> &x) {
	return search(root, x);
}

template <typename T>
BSTNode<T>* BST<T>::search(BSTNode<T> *b, const element<T> &x) {
	if (!b)
		return nullptr;
	if (x.key == b->data.key)
		return b;
	if (x.key < b->data.key)
		return search(b->leftChild, x);
	return search(b->rightChild, x);
}

template <typename T>
BSTNode<T>* BST<T>::IterSearch(const element<T> &x) {
	for (BSTNode<T> *t = root; t;) {
		if (x.key == t->data.key)
			return t;
		if (x.key < t->data.key)
			t = t->leftChild;
		else
			t = t->rightChild;
	}

	return nullptr;
}

#endif // !BINARYSEARCHTREE_H
/*BST<int> m;
	element<int> a, b, c, d, e, f, g, h, i, j;// k, l;
	a.key = 5;
	b.key = 3;
	c.key = 11;
	d.key = 3;
	e.key = 15;
	f.key = 2;
	g.key = 8;
	h.key = 22;
	i.key = 20;
	j.key = 9;
	cout << m.Insert(a) << endl;
	cout << m.Insert(b) << endl;
	cout << m.Insert(c) << endl;
	cout << m.Insert(d) << endl;
	cout << m.Insert(e) << endl;
	cout << m.Insert(f) << endl;
	cout << m.Insert(g) << endl;
	cout << m.Insert(h) << endl;
	cout << m.Insert(i) << endl;
	cout << m.Insert(j) << endl;
	m.display();

	BSTNode<int> *p = m.search(f);
	cout << p->data.key << endl;*/