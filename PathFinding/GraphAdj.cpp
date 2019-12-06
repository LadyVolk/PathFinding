#include "GraphAdj.h"
#include <iostream>
#include <utility>
using namespace std;

GraphAdj::GraphAdj(int size) {
	int i, j;
	V = size;
	A = 0;

	Pos = new pair <int, int>[V];
	Adj = new bool* [V];
	Cost = new int* [V];

	//initialising adjancency matrix
	for (i = 0; i < V; i++) {
		Adj[i] = new bool[V];
		for (j = 0; j < V; j++) {
			Adj[i][j] = false;
		}
	}
	//initialising cost matrix (-1 is undefined cost)
	for (i = 0; i < V; i++) {
		Cost[i] = new int[V];
		for (j = 0; j < V; j++) {
			Cost[i][j] = -1;
		}
	}
	//inicial position for all vertices for a*
	for (i = 0; i < V; i++) {
		Pos[i].first = 0;
		Pos[i].second = i;
	}
}

GraphAdj::~GraphAdj() {
	int i;

	for (i = 0; i < V; i++) {
		delete [] Adj[i];
	}
	delete [] Adj;

	for (i = 0; i < V; i++) {
		delete[] Cost[i];
	}
	delete[] Cost;
	delete[] Pos;
}

void GraphAdj::InsertArc(int v, int w, int cost) {
	if (!Adj[v][w]){
		Adj[v][w] = true;
		A++;
		Cost[v][w] = cost;
	}
}
void GraphAdj::RemoveArc(int v, int w) {
	if (Adj[v][w]) {
		Adj[v][w] = false;
		A--;
		Cost[v][w] = -1;
	}
}

void GraphAdj::Draw() {
	int i, j;
	for (i = 0; i < V; i++) {
		cout << i << ": ";
		for (j = 0; j < V; j++) {
			if (Adj[i][j]) {
				cout << j << "(" << GetCost(i, j) << ") ";
			}
		}
		cout << endl;
	}
}
int GraphAdj::GetArc() {
	return A;
}

bool GraphAdj::IsArc(int v, int w) {
	return Adj[v][w];
}

int GraphAdj::GetV() {
	return V;
}
int GraphAdj::GetInDegree(int v) {
	int i, indegree =0;
	for (i = 0; i < V; i++) {
		if (Adj[i][v]) {
			indegree++;
		}
	}
	return indegree;
}
int GraphAdj::GetOutDegree(int v) {
	int i, outdegree = 0;
	for (i = 0; i < V; i++) {
		if (Adj[v][i]) {
			outdegree++;
		}
	}
	return outdegree;
}
int GraphAdj::GetCost(int v, int w) {
	return Cost[v][w];
}
void GraphAdj::SetPos(int v, int x, int y) {
	Pos[v].first = x;
	Pos[v].second = y;
}
pair <int, int> GraphAdj::GetPos(int v) {
	return Pos[v];
}
