#ifndef GRAPH_ADJACENCYMATRIX_H
#define GRAPH_ADJACENCYMATRIX_H
#define MAX_VERTS 100
#include "husky.h"

#include <stack>		//DFS
#include <queue>		//BFS

//顶点
class vertex {
private:
public:
	char label;
	vertex(char lab):label(lab), wasVisited(false) { } 
	bool wasVisited;
};

//图
class Graph {
private:
	vertex *vertexList[MAX_VERTS];	//保存顶点
	int nVerts;		//顶点数
	int adjMat[MAX_VERTS][MAX_VERTS];		//矩阵

	int getAdjUnvisitedVertex(int v);
public:
	Graph();
	~Graph();
	void addVertex(char lab);
	void addEdge(int start, int end);
	void printMatrix();

	void showVertex(int v) { std::cout << vertexList[v]->label << std::ends; }
	void DFS();

	void BFS();
};

Graph::Graph() {
	nVerts = 0;
	for (int i = 0; i < MAX_VERTS; ++i)
		for (int j = 0; j < MAX_VERTS; ++j)
			adjMat[i][j] = 0;
}

Graph::~Graph() {
	for (int i = 0; i < nVerts; ++i)
		delete vertexList[i];
}

void Graph::addVertex(char lab) {
	vertexList[nVerts++] = new vertex(lab);
}

void Graph::addEdge(int start, int end) {
	adjMat[start][end] = 1;
	adjMat[end][start] = 1;
}

void Graph::printMatrix() {
	for (int i = 0; i < nVerts; ++i) {
		for (int j = 0; j < nVerts; ++j)
			std::cout << adjMat[i][j] << std::ends;
		std::cout << std::endl;
	}
}

int Graph::getAdjUnvisitedVertex(int v) {
	for (int j = 0; j < nVerts; ++j)
		if ((adjMat[v][j] == 1) && (vertexList[j]->wasVisited == false))
			return j;
	return -1;
}

void Graph::DFS() {
	std::stack<int> gStack;		//保存顶点下标
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gStack.push(0);
	int v;
	while (gStack.size() > 0) {
		v = getAdjUnvisitedVertex(gStack.top());
		if (v == -1)
			gStack.pop();
		else {
			vertexList[v]->wasVisited = true;
			showVertex(v);
			gStack.push(v);
		}
	}
	std::cout << std::endl;
	for (int j = 0; j < nVerts; ++j)
		vertexList[j]->wasVisited = false;
}

void Graph::BFS() {
	std::queue<int> gQueue;
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gQueue.push(0);
	int vert1, vert2;
	while (gQueue.size() > 0) {
		vert1 = gQueue.front();
		gQueue.pop();
		vert2 = getAdjUnvisitedVertex(vert1);
		while (vert2 != -1) {
			vertexList[vert2]->wasVisited = true;
			showVertex(vert2);
			gQueue.push(vert2);
			vert2 = getAdjUnvisitedVertex(vert1);
		}
	}

	std::cout << std::endl;
	for (int j = 0; j < nVerts; ++j)
		vertexList[j]->wasVisited = false;
}

#endif
/*Graph g;
	g.addVertex('A');
	g.addVertex('B');
	g.addVertex('C');
	g.addVertex('D');
	g.addVertex('E');
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.printMatrix();
	
	g.DFS();
	g.BFS();
	*/