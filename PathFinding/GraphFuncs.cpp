#include "GraphFuncs.h"
#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "PriorityQueue.h"
using namespace std;

GraphAdj* RandomGraph1(int v, int a) {
	float rand1, rand2;
	int cost;
	GraphAdj* graph;

	graph = new GraphAdj(v);

	while (graph->GetArc() < a) {

		rand1 = rand() % v;
		rand2 = rand() % v;
		if (rand1 != rand2) {
			cost = rand() % 100;
			graph->InsertArc(rand1, rand2, cost);
		}
	}
	return graph;
}

GraphAdj* RandomGraph2(int size, int a) {
	GraphAdj* graph;
	int v, w, cost;

	float probs, r;
	probs = (float)a / (size * (size - 1));
	graph = new GraphAdj(size);

	for (v = 0; v < size; v++) {
		for (w = 0; w < size; w++) {
			if (v != w) {
				r = (float)rand() / RAND_MAX;
				if (r <= probs) {
					cost = rand() % 100;
					graph->InsertArc(v, w, cost);
				}
			}
		}
	}

	return graph;
}

bool CheckWalk(GraphAdj* graph, int *seq, int seq_size) {
	int i;
	for (i = 0; i <= seq_size - 2; i++) {
		if (!graph->IsArc(seq[i], seq[i + 1])) {
			return false;
		}
	}
	return true;
}

bool CheckPath(GraphAdj* graph, int seq[], int seq_size) {
	int i, j;
	bool** matrix;
	matrix = new bool* [graph->GetV()];
	for (i = 0; i < graph->GetV(); i++) {
		matrix[i] = new bool[graph->GetV()];
		for (j = 0; j < graph->GetV(); j++) {
			matrix[i][j] = false;
		}
	}
	for (i = 0; i <= seq_size - 2; i++) {
		if (!graph->IsArc(seq[i], seq[i + 1]) ||
			matrix[seq[i]][seq[i + 1]]) {
			return false;
		}

		matrix[seq[i]][seq[i + 1]] = true;

	}
	for (i = 0; i < graph->GetV(); i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return true;
}

bool CheckSimplePath(GraphAdj* graph, int seq[], int seq_size) {
	int i;
	bool* a;
	if (CheckPath(graph, seq, seq_size)) {
		a = new bool[graph->GetV()];
		for (i = 0; i < graph->GetV(); i++) {
			a[i] = false;
		}
		for (i = 0; i < seq_size; i++) {
			if (a[seq[i]]) {
				delete[] a;
				return false;
			}
			a[seq[i]] = true;
		}
		delete[] a;
		return true;
	}
	else {
		return false;
	}
}

bool CheckCycle(GraphAdj* graph, int seq[], int seq_size) {
	return (CheckPath(graph, seq, seq_size) &&
		seq[0] == seq[seq_size - 1] &&
		seq_size > 1);
}

bool CheckSimpleCycle(GraphAdj* graph, int seq[], int seq_size) {
	int i;
	bool* a;
	if (CheckCycle(graph, seq, seq_size)) {
		a = new bool[graph->GetV()];
		for (i = 0; i < graph->GetV(); i++) {
			a[i] = false;
		}
		for (i = 0; i < seq_size - 1; i++) {
			if (a[seq[i]]) {
				delete[] a;
				return false;
			}
			a[seq[i]] = true;
		}
		delete[] a;
		return true;

	}
	else {
		return false;
	}
}
GraphAdj* RemoveV(GraphAdj* graph_old, int vertex) {
	int i, j, new_i, new_j, cost = rand() % 100;
	GraphAdj* graph = new GraphAdj(graph_old->GetV()-1);
	for (i = 0; i < graph_old->GetV(); i++) {
		for (j = 0; j < graph_old->GetV(); j++) {
			if (i != vertex && j != vertex && graph_old->IsArc(i, j)) {
				new_i = i;
				if (i > vertex) {
					new_i = i - 1;
				}
				new_j = j;
				if (j > vertex) {
					new_j = j - 1;
				}
				graph->InsertArc(new_i, new_j, graph_old->GetCost(i, j));
			}
		}
	}
	delete graph_old;
	return graph;
}
GraphAdj* CopyGraph(GraphAdj* old_graph) {
	int i, j;
	GraphAdj* graph= new GraphAdj(old_graph->GetV());
	
	for (i = 0; i < graph->GetV(); i++) {
		for (j = 0; j < graph->GetV(); j++) {
			if (old_graph->IsArc(i, j)) {
				graph->InsertArc(i, j, old_graph->GetCost(i, j));
			}
		}
	}
	return graph;
}
bool IsTopological(GraphAdj* graph) {
	int i, j = 0;
	bool was_removed = true;
	GraphAdj* new_graph;

	new_graph = CopyGraph(graph);
	while (new_graph->GetV() > 0 && was_removed) {
		was_removed = false;
		for (i = 0; i < new_graph->GetV(); i++) {
			if (!new_graph->GetInDegree(i)) {
				new_graph = RemoveV(new_graph, i);
				was_removed = true;
			}
		}
	}
	return (new_graph->GetV() == 0);
}

bool Reach(GraphAdj* graph, int vi, int vf) {
	bool *visited, result;
	int i;
	visited = new bool[graph->GetV()];
	for (i = 0; i < graph->GetV(); i++) {
		visited[i] = false;
	}
	visit_adj(graph, vi, visited);
	
	result = visited[vf];

	delete[] visited;

	return result;
}

void visit_adj(GraphAdj* graph, int v, bool* visited) {
	int i;

	visited[v] = true;

	for (i = 0; i < graph->GetV(); i++) {
		if (graph->IsArc(v, i) && !visited[i]) {
			visit_adj(graph, i, visited);
		}
	}
}

void BFS(GraphAdj* graph, int initial, int *num, int *parent) {
	Queue *queue;
	int i, v, cont = 0;
	queue = new Queue(graph->GetV());

	for (i = 0; i < graph->GetV(); i++) {
		num[i] = -1;
		parent[i] = -1;
	}

	num[initial] = cont++;
	parent[initial] = initial;

	queue->Enqueue(initial);
	while (!queue->IsEmpty()) {
		v = queue->Dequeue();
		for (i = 0; i < graph->GetV(); i++) {
			if (graph->IsArc(v, i) && num[i] == -1) {

				parent[i] = v;

				num[i] = cont++;
				
				queue->Enqueue(i);
			}
		}
	}

	delete queue;
}
void BFSEarlyExit(GraphAdj* graph, int initial, int* num, int* parent, int vf) {
	Queue* queue;
	bool early_exit = false;
	int i, v, cont = 0;
	queue = new Queue(graph->GetV());

	for (i = 0; i < graph->GetV(); i++) {
		num[i] = -1;
		parent[i] = -1;
	}

	num[initial] = cont++;
	parent[initial] = initial;

	queue->Enqueue(initial);
	while (!queue->IsEmpty()) {
		v = queue->Dequeue();
		for (i = 0; i < graph->GetV(); i++) {
			if (graph->IsArc(v, i) && num[i] == -1) {

				parent[i] = v;

				num[i] = cont++;

				queue->Enqueue(i);

				if (i == vf) {
					early_exit = true;
					break;
				}
			}
		}
		if (early_exit) {
			break;
		}
	}
	delete queue;
}
void Pre_Dijkstra(GraphAdj* graph, int initial, int* parent, int vf) {
	PriorityQueue* queue;
	int i, v, *cost, temp_cost;
	queue = new PriorityQueue();
	cost = new int[graph->GetV()];

	for (i = 0; i < graph->GetV(); i++) {
		parent[i] = -1;
		cost[i] = -1;
	}

	parent[initial] = initial;
	cost[initial] = 0;

	queue->Enqueue(initial, 0);
	while (!queue->IsEmpty()) {
		v = queue->Dequeue();
		if (v == vf) {
			break;
		}
		for (i = 0; i < graph->GetV(); i++) {
			temp_cost = cost[v] + graph->GetCost(v, i);
			if (graph->IsArc(v, i) && 
				(cost[i] == -1 || temp_cost < cost[i])) {

				cost[i] = temp_cost;

				parent[i] = v;

				queue->Enqueue(i, temp_cost);
			}
		}
	}
	delete[] cost;
	delete queue;
}

GraphAdj* GridGraph(int width, int height) {
	int i, j, v = 0;
	GraphAdj *grid;

	grid = new GraphAdj(width*height);
	
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			grid->SetPos(v, j, i);
			v++;
		}
	}

	for (v = 0; v < grid->GetV(); v++) {
		int x, y;
		x = grid->GetPos(v).first;
		y = grid->GetPos(v).second;
		if (y > 0) {
			grid->InsertArc(v, v-width, 0);
		}
		if (x < width-1) {
			grid->InsertArc(v, v + 1, 0);
		}
		if (y < height-1) {
			grid->InsertArc(v, v + width, 0);
		}
		if (x > 0) {
			grid->InsertArc(v, v-1, 0);
		}
	}
	return grid;
}

void CreateWall(GraphAdj *grid, int v, int width, int height) {
	int x, y;
	x = grid->GetPos(v).first;
	y = grid->GetPos(v).second;
	if (y > 0) {
		grid->RemoveArc(v, v - width);
		grid->RemoveArc(v - width, v);
	}
	if (x < width - 1) {
		grid->RemoveArc(v, v + 1);
		grid->RemoveArc(v + 1, v);
	}
	if (y < height - 1) {
		grid->RemoveArc(v, v + width);
		grid->RemoveArc(v + width, v);
	}
	if (x > 0) {
		grid->RemoveArc(v, v - 1);
		grid->RemoveArc(v - 1, v);
	}
}

GraphAdj* RandomGrid(int walls, int width, int height) {
	int i;
	float probs, r;
	GraphAdj *graph;
	graph  = GridGraph(width, height);
	probs = (float)walls / graph->GetV();
	for (i = 0; i < graph->GetV(); i++) {
		r = (float)rand() / RAND_MAX;
		if (r <= probs) {
			CreateWall(graph, i, width, height);
		}
	}
	return graph;
}