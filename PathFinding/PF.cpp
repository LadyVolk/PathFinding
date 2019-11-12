#include "PF.h"
#include <iostream>
#include "GraphFuncs.h"
#include <time.h>
#include <chrono>
using namespace std;
namespace	PF
{
	void BFS(GraphAdj* graph, int vi, int vf) {
		int i, j, *parent, *num, *order_path;

		parent = new int [graph->GetV()];
		num = new int[graph->GetV()];
		order_path = new int[graph->GetV()];

		BFS(graph, vi, num, parent);

		if (parent[vf] != -1) {
			j = 0;
			i = vf;
			while (i != vi) {
				order_path[j] = i;
				i = parent[i];
				j++;
			}
			order_path[j] = vi;
			for (i=j; i >= 0; i--) {
				cout << order_path[i];
				if (i != 0) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
		else {
			cout << "there is no path between " << vi <<
				" and " << vf << endl;
		}
		delete[] parent;
		delete[] num;
		delete[] order_path;	
	}

	void BFSEarlyExit(GraphAdj* graph, int vi, int vf) {
		int i, j, * parent, * num, * order_path;
		
		parent = new int[graph->GetV()];
		num = new int[graph->GetV()];
		order_path = new int[graph->GetV()];

		BFSEarlyExit(graph, vi, num, parent, vf);

		if (parent[vf] != -1) {
			j = 0;
			i = vf;
			while (i != vi) {
				order_path[j] = i;
				i = parent[i];
				j++;
			}
			order_path[j] = vi;
			for (i = j; i >= 0; i--) {
				cout << order_path[i];
				if (i != 0) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
		else {
			cout << "there is no path between " << vi <<
				" and " << vf << endl;
		}
		delete[] parent;
		delete[] num;
		delete[] order_path;
		
	}

	void Dijkstra(GraphAdj* graph, int vi, int vf) {
		int i, j, *parent, *order_path;
		auto t1 = chrono::high_resolution_clock::now();
		parent = new int[graph->GetV()];
		order_path = new int[graph->GetV()];

		PreDijkstra(graph, vi, parent, vf);

		if (parent[vf] != -1) {
			j = 0;
			i = vf;
			while (i != vi) {
				order_path[j] = i;
				i = parent[i];
				j++;
			}
			order_path[j] = vi;
			for (i = j; i >= 0; i--) {
				cout << order_path[i];
				if (i != 0) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
		else {
			cout << "there is no path between " << vi <<
				" and " << vf << endl;
		}
		delete[] parent;
		delete[] order_path;
		auto t2 = chrono::high_resolution_clock::now();
		cout << "time to execute: " <<
		chrono::duration<double>(t2 - t1).count() << endl;
	}
	void AStar(GraphAdj* graph, int vi, int vf) {
		int i, j, * parent, * order_path;
		auto t1 = chrono::high_resolution_clock::now();
		parent = new int[graph->GetV()];
		order_path = new int[graph->GetV()];

		PreAStar(graph, vi, parent, vf);

		if (parent[vf] != -1) {
			j = 0;
			i = vf;
			while (i != vi) {
				order_path[j] = i;
				i = parent[i];
				j++;
			}
			order_path[j] = vi;
			for (i = j; i >= 0; i--) {
				cout << order_path[i];
				if (i != 0) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
		else {
			cout << "there is no path between " << vi <<
				" and " << vf << endl;
		}
		delete[] parent;
		delete[] order_path;
		auto t2 = chrono::high_resolution_clock::now();
		cout << "time to execute: " <<
			chrono::duration<double>(t2 - t1).count() << endl;
	}
}
