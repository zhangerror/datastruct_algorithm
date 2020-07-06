#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "wrapper.h"

template <typename T> class redBlackTree;

template <typename T>
class redBlackNode {
	friend class redBlackTree<T>;

public:///临时
	T element;
	redBlackNode *left;
	redBlackNode *right;
	int color;
	redBlackNode( const T & theElement = T(),
		redBlackNode *lt = nullptr,
		redBlackNode *rt = nullptr,
		int c = redBlackTree<T>::BLACK)
		:element(theElement),left(lt), right(rt), color(c) { }

};

template <typename T>
class redBlackTree {
public:
	typedef redBlackNode<T> Node;
	redBlackTree(const T & negInf);
	enum {RED, BLACK};
	~redBlackTree();
	void insert(const T &x);

	void rotateWithLeftChild(Node* &k2) const;
	void rotateWithRightChild(Node* &k1) const;

	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithRightChild(Node* &k1) const;

	void handleReorient(const T &item);
	redBlackNode<T>* rotate(const T &item, Node *theParent) const;

	bool isEmpty() const { return header->right == nullNode; }
	void makeEmpty() {
		reclaimMemory(header->right);
		header->right = nullNode;
	}
	mycref<T> find(const T &x) const;
	mycref<T> findMin() const;
	mycref<T> findMax() const;

//private:
	Node *header;
	Node *nullNode;
	Node *current;
	Node *parent;
	Node *grand;
	Node *great;
	void reclaimMemory(Node *t) const;
};

template <typename T>
redBlackTree<T>::redBlackTree(const T & negInf) {
	nullNode = new Node();
	nullNode->left = nullNode;
	nullNode->right = nullNode;
	header = new Node(negInf);
	header->left = nullNode;
	header->right = nullNode;
}

template <typename T>
redBlackTree<T>::~redBlackTree() {
	makeEmpty();
	delete nullNode;
	delete header;
}

template <typename T>
void redBlackTree<T>::insert(const T &x) {
	current = header;
	parent = header;
	grand = header;
	nullNode->element = x;
	while (current->element != x) {
		great = grand;
		grand = parent;
		parent = current;
		current = x < current->element ? current->left : current->right;
		if (current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}
	if (current != nullNode)
		throw DuplicateItemException( string("The current node already exists"));
	current = new Node(x, nullNode, nullNode);
	if (x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	handleReorient(x);
}

template <typename T>
void redBlackTree<T>::rotateWithLeftChild(Node* &k2) const {	//指针引用：最后能传回去的是k2这个节点，应该把旋转后的k1上升给k2
	Node *k1 = k2->left;
	k2->left = k1->right;		//横向移动
	k1->right = k2;
	k2 = k1;		//k1上升为k2
}

template <typename T>
void redBlackTree<T>::rotateWithRightChild(Node* &k1) const {
	Node *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}

template <typename T>
void redBlackTree<T>::doubleRotateWithLeftChild(Node* &k3) const {
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <typename T>
void redBlackTree<T>::doubleRotateWithRightChild(Node* &k1) const {
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

template <typename T>
void redBlackTree<T>::handleReorient(const T &item) {
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;
	if (parent->color == RED) {
		grand->color = RED;
		if ((item < grand->element) != (item < parent->element))	//内孙，双旋转
			parent = rotate(item, grand);
		current = rotate(item, great);
		current->color = BLACK;
	}

	header->right->color = BLACK;
}

template <typename T>
redBlackNode<T>* redBlackTree<T>::rotate(const T &item, Node *theParent) const {
	if (item < theParent->element) {
		item < theParent->left->element ?
			rotateWithLeftChild(theParent->left) :
			rotateWithRightChild(theParent->left);
		return theParent->left;
	}
	else {
		item < theParent->right->element ?
			rotateWithLeftChild(theParent->right) :
			rotateWithRightChild(theParent->right);
		return theParent->right;
	}
}

template <typename T> 
void redBlackTree<T>::reclaimMemory( Node *t) const {
	if (t != t->left) {	//已到叶子节点，左右为空
		reclaimMemory(t->left);
		reclaimMemory(t->right);
		delete t;
	}
}

template <typename T> 
mycref<T> redBlackTree<T>::findMin() const {
	if (isEmpty())
		return mycref<T>();
	Node *itr = header->right;
	while (itr->left != nullNode)
		itr = itr->left;
	return mycref<T>(itr->element);
}

template <typename T>
mycref<T> redBlackTree<T>::findMax() const {
	if (isEmpty())
		return mycref<T>();
	Node *itr = header->right;
	while (itr->right != nullNode)
		itr = itr->right;
	return mycref<T>(itr->element);
}

template <typename T>
mycref<T> redBlackTree<T>::find( const T &x) const {
	if (isEmpty())
		return mycref<T>();
	nullNode->element = x;
	Node *curr = header->right;
	while (1) {
		if (x < curr->element)
			curr = curr->left;
		else if (x > curr->element)
			curr = curr->right;
		else if (curr != nullNode)
			return mycref<T>(curr->element);
		else
			return mycref<T>();
	}
}

#endif // !REDBLACKTREE_H

/*
	const int NEG_INF = INT_MIN;
	redBlackTree<int> t(NEG_INF);*/

	/*
	t.insert(30);
	t.insert(15);
	t.insert(70);
	t.insert(20);

	cout << t.header->right->element << endl;
	cout << t.header->right->left->element << endl;
	cout << t.header->right->right->element << endl;
	cout << t.header->right->left->right->element << endl;	//30

	cout << "rotate" << endl;
	t.rotateWithLeftChild(t.header->right);
	cout << t.header->right->element << endl;	//15
	cout << t.header->right->right->element << endl;
	cout << t.header->right->left->element << endl;
	cout << t.header->right->right->right->element << endl;	*/

	/*
	t.insert(12);
	t.insert(16);
	t.insert(8);
	t.insert(10);
	t.insert(4);
	t.insert(18);
	t.insert(2);
	t.insert(6);
	t.insert(5);

	cout << t.header->right->element << endl;	//12
	cout << t.header->right->left->left->right->left->element << endl;	//5
	t.doubleRotateWithLeftChild(t.header->right->left);	//8双旋转
	cout << t.header->right->left->left->right->element << endl;	//5*/

	/*
	t.insert(50);
	t.insert(40);
	t.insert(30);
	t.insert(20);

	cout << t.header->right->element << endl;	//40

	if (!t.isEmpty())
		cout << " Not Null" << endl;
	t.makeEmpty();
	if (t.isEmpty())
		cout << "Null" << endl;
	t.insert(200);
	t.insert(100);
	t.insert(90);
	t.insert(50);
	t.insert(80);
	t.insert(70);
	t.insert(60);

	if (t.findMin().get() == 50)
		cout << "found the min" << endl;
	cout << "max: " << t.findMax().get() << endl;
	mycref<int> r = t.find(80);
	if (r.isNull())
		cout << " no element";
	else
		cout << "found: " << r.get() << endl;*/
