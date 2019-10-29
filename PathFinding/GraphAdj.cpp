#include "GraphAdj.h"
#include <iostream>
using namespace std;

GraphAdj::GraphAdj(int size) {
	int i, j;
	V = size;
	A = 0;
	Adj = new bool* [V];
	for (i = 0; i < V; i++) {
		Adj[i] = new bool[V];
		for (j = 0; j < V; j++) {
			Adj[i][j] = false;
		}
	}
}

GraphAdj::~GraphAdj() {
	int i;

	for (i = 0; i < V; i++) {
		delete [] Adj[i];
	}
	delete [] Adj;
}

void GraphAdj::InsertArc(int v, int w) {
	if (!Adj[v][w]){
		Adj[v][w] = true;
		A++;
	}
}
void GraphAdj::RemoveArc(int v, int w) {
	if (Adj[v][w]) {
		Adj[v][w] = false;
		A--;
	}
}

void GraphAdj::Draw() {
	int i, j;
	for (i = 0; i < V; i++) {
		cout << i << ": ";
		for (j = 0; j < V; j++) {
			if (Adj[i][j]) {
				cout << j << " ";
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
