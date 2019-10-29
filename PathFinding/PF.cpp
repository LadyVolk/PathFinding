#include "PF.h"
#include <iostream>
#include "GraphFuncs.h"
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
}