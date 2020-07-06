#ifndef GRAPH_ADJACENCYLIST_H
#define GRAPH_ADJACENCYLIST_H
#include "husky.h"
#include <list>

class Vertex {
public:
	char label;
	Vertex(char lab) :label(lab) {}
};

std::ostream & operator<<(std::ostream & os, const Vertex &v)
{
	os << v.label;
	return os;
}

template <typename T>
class GraphL {
private:
	T **vertexList;				//存顶点的数组
	std::list<int> *headNodes;	//存边的链表
	int n;						//最大顶点数
	int nVerts;					//当前顶点个数

public:
	GraphL(const int vertices) :n(vertices) {
		vertexList = new T*[n];				//指向顶点
		headNodes = new std::list<int>[n];	//链表
		nVerts = 0;
	}
	~GraphL() {
		delete[] vertexList;
		delete[] headNodes;
	}
	void addVertex(T *v);
	void addEdge(int start, int end);
	void printVertice();
	void printAdjList();
};

template <typename T>
void GraphL<T>::addVertex(T *v) {
	vertexList[nVerts++] = v;
}

template <typename T>
void GraphL<T>::addEdge(int start, int end) {
	headNodes[start].push_back(end);
}

template <typename T>
void GraphL<T>::printVertice() {
	for (int i = 0; i < nVerts; ++i){
		std::cout << *vertexList[i] << std::ends;
		std::cout << std::endl;
	}
}

template <typename T>
void GraphL<T>::printAdjList() {
	for (int i = 0; i < nVerts; ++i) {
		std::cout << i << " -> ";
		for (std::list<int>::iterator iter = headNodes[i].begin();
			iter != headNodes[i].end(); ++iter) 
			std::cout << *iter << " -> ";
		std::cout << " end " << std::endl;
		
	}
}

#endif // !GRAPH_ADJACENCYLIST_H

/*GraphL<Vertex> g(5);
	Vertex a('A');
	Vertex b('B');
	Vertex c('C');
	Vertex d('D');
	Vertex e('E');

	g.addVertex(&a);
	g.addVertex(&b);
	g.addVertex(&c);
	g.addVertex(&d);
	g.addVertex(&e);
	
	g.printVertice();

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 0);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);

	g.printAdjList();*/