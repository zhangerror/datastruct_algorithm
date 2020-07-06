#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "husky.h"
#include <list>
#include <queue>

template <typename T>
class treeNode {
public:
	treeNode() {
		leftChild = nullptr;
		rightChild = nullptr;
	}
	treeNode<T> *leftChild;
	treeNode<T> *rightChild;
	T data;
};

template <typename T>
class binaryTree {
public:
	void inOrder();
	void inOrder(treeNode<T> *currentNode);
	void preOrder();
	void preOrder(treeNode<T> *currentNode);
	void postOrder();
	void postOrder(treeNode<T> *currentNode);
	void levelOrder();
	void visit(treeNode<T> *currentNode);

	treeNode<T> *root;
};

template <typename T>
void binaryTree<T>::visit(treeNode<T>* currentNode) {
	std::cout << currentNode->data;
}

template <typename T>
void binaryTree<T>::inOrder() {
	inOrder(root);
}

template <typename T>
void binaryTree<T>::inOrder(treeNode<T> *currentNode) {
	if (currentNode) {
		inOrder(currentNode->leftChild);
		visit(currentNode);
		inOrder(currentNode->rightChild);
	}
}

template <typename T>
void binaryTree<T>::preOrder() {
	preOrder(root);
}

template <typename T>
void binaryTree<T>::preOrder(treeNode<T> *currentNode) {
	if (currentNode) {
		visit(currentNode);
		preOrder(currentNode->leftChild);
		preOrder(currentNode->rightChild);
	}
}

template <typename T> 
void binaryTree<T>::postOrder() {
	postOrder(root);
}

template <typename T>
void binaryTree<T>::postOrder(treeNode<T> *currentNode) {
	if (currentNode) {
		postOrder(currentNode->leftChild);
		postOrder(currentNode->rightChild);
		visit(currentNode);
	}
}

template <typename T>
void binaryTree<T>::levelOrder() {
	std::queue<treeNode<T>*> q;
	treeNode<T> *currentNode = root;

	//显示队头，并将其左右孩子加入队列
	while (currentNode) {
		visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front();
		q.pop();
	}
}

#endif // !BINARYTREE_H

/*treeNode<char> add, sub, mul, dev, a, b, c, d, e;
	add.data = '+';
	sub.data = '-';
	mul.data = '*';
	dev.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';
	binaryTree<char> tree;
	tree.root = &add;
	add.leftChild = &sub;
	add.rightChild = &e;
	sub.leftChild = &mul;
	sub.rightChild = &d;
	mul.leftChild = &dev;
	mul.rightChild = &c;
	dev.leftChild = &a;
	dev.rightChild = &b;

	tree.inOrder();
	cout << endl;
	tree.preOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	tree.levelOrder();
	cout << endl;*/