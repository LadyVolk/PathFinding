#include <iostream>
#include "GraphAdj.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include "GraphFuncs.h"
#include "Input.h"
#include "PF.h"
#include "PriorityQueue.h"
using namespace std;

int main()
{
	string input;
	pair<int*, int> sequence;
	int v, w, a, i, *num, *aux, *parent, cost, walls;
	GraphAdj* graph;
	PriorityQueue* queue;
	srand(time(NULL));

	cout << "press 1 for random graph " << endl;
	cout << "press 2 to create an empty graph" << endl;
	cout << "press 3 to create a grid" << endl;
	cout << "press 4 to create a grid with walls" << endl;

	cin >> input;

	if (input == "1") {
		cout << "choose method, how many vertices and arcs" << endl;
		cin >> input >> v >> a;
		if (input == "2") {
			graph = RandomGraph2(v, a);
		}
		else if (input == "1") {
			graph = RandomGraph1(v, a);
		}
		else {
			return 0;
		}
		
	}
	else if (input == "2") {
		cout << "how many vertices do you want?" << endl;
		cin >> v;
		graph = new GraphAdj(v);
	}
	else if (input == "3") {
		cout << "tell me the width and height do you want?" << endl;
		cin >> w >> v;
		graph = GridGraph(w, v);
	}
	else if (input == "4") {
		cout << "tell me the width and height do you want?" << endl;
		cin >> w >> v;
		cout << "now tell me the number of walls" << endl;
		cin >> walls;
		graph = RandomGrid(walls, w, v);
	}
	else {
		return 0;
	}

	while (true) {

		cout << "--------------------" << endl;
		cout << "type 'add' to add an arc and its cost" << endl;
		cout << "type 'remove' to remove an arc" << endl;
		cout << "type 'draw' to draw the graph" << endl;
		cout << "type 'walk' to check a walk" << endl;
		cout << "type 'path' to check a path" << endl;
		cout << "type 'simplep' to check a simple path" << endl;
		cout << "type 'cycle' to check cycle" << endl;
		cout << "type 'simplec' to check simple cycle" << endl;
		cout << "type 'removev' to remove an vertex" << endl;
		cout << "type 'topo' to check if the graph is topological" << endl;
		cout << "type 'acessible' to check if there is a pth between two v" << endl;
		cout << "type 'bfs' to search the graph" << endl;
		cout << "type 'pf_bfs' to run pathfinding by bfs" << endl;
		cout << "type 'pf_early' to run pathfinding by bfs with early exit" << endl;
		cout << "type 'dijkstra' to run dijkstra pathfinding" << endl;
		cout << "type 'astar' to run the A* pathfinding" << endl;
		cout << "type 'exit' to exit the program" << endl;

		cin >> input;

		if (input == "add") {
			cout << "type two vertices to add an arc in between" << endl;
			cin >> v >> w;
			cout << "now insert the cost(your life)" << endl;
			cin >> cost;
			graph->InsertArc(v, w, cost);
		}
		else if (input == "remove") {
			cout << "type two vertices to remove an arc in between" << endl;
			cin >> v >> w;
			graph->RemoveArc(v, w);
		}
		else if (input == "draw") {
			cout << endl;
			graph->Draw();
		}
		else if (input == "walk") {
			sequence = AskSequence();
			if (CheckWalk(graph, sequence.first, sequence.second)) {
				cout << "the sequence is a walk" << endl;
			}
			else {
				cout << "the sequence is not a walk" << endl;
			}
			delete [] sequence.first;
			
		}
		else if (input == "path") {
			sequence = AskSequence();
			if (CheckPath(graph, sequence.first, sequence.second)) {
				cout << "the sequence is a path" << endl;
			}
			else {
				cout << "the sequence is not a path" << endl;
			}
			delete[] sequence.first;
		}
		else if (input == "simplep") {
			sequence = AskSequence();
			if (CheckSimplePath(graph, sequence.first, sequence.second)) {
				cout << "the sequence is a simple path" << endl;
			}
			else {
				cout << "the sequence is not a simple path" << endl;
			}
			delete[] sequence.first;
		}
		else if (input == "cycle") {
			sequence = AskSequence();
			if (CheckCycle(graph, sequence.first, sequence.second)) {
				cout << "the sequence is a cycle" << endl;
			}
			else {
				cout << "the sequence is not a cycle" << endl;
			}
			delete[] sequence.first;
		}
		else if (input == "simplec") {
			sequence = AskSequence();
			if (CheckCycle(graph, sequence.first, sequence.second)) {
				cout << "the sequence is a simple cycle" << endl;
			}
			else {
				cout << "the sequence is not a simple cycle" <<  endl;
			}
			delete[] sequence.first;
		}
		else if (input == "removev") {
			cout << "insert the vertex you wish to remove" << endl;
			cin >> v;
			graph = RemoveV(graph, v);
		}
		else if (input == "topo") {
			if (IsTopological(graph)) {
				cout << "the graph is topological" << endl;
			}
			else {
				cout << "graph is not topological" << endl;
			}
		}
		else if (input == "acessible") {
			cout << "type origin and destination vertices" << endl;
			cin >> v >> w;
			if (Reach(graph, v, w)) {
				cout << "there is a path between " << v << " and " << w << endl;
			}
			else {
				cout << "there is no path between " << v << " and " << w << endl;
			}
		}
		else if (input == "bfs") {
			cout << "type which v you would like to start the search" << endl;
			cin >> v;
			num = new int[graph->GetV()];
			parent = new int[graph->GetV()];


			BFS(graph, v, num, parent);

			aux = new int[graph->GetV()];

			for (i = 0; i < graph->GetV(); i++) {
				aux[i] = -1;
			}

			for (i = 0; i < graph->GetV(); i++) {
				if (num[i] != -1) {
					aux[num[i]] = i;
				}
			}
			cout << endl << "parent array:" << endl;
			for (i = 0; i < graph->GetV(); i++) {
				cout << i << ":" << parent[i] << " ";
			}
			cout << endl << "vertices in order of visit:" << endl;
			for (i = 0; i < graph->GetV(); i++) {
				if (aux[i] != -1) {
					cout << aux[i] << " ";
				}
			}
			cout << endl << "topological order:" << endl;
			for (i = 0; i < graph->GetV(); i++) {
				cout << num[i] << " ";
			}
			cout << endl;
			delete[] num;
			delete[] aux;
		}
		else if (input == "pf_bfs") {
			cout << "type the initial and final vertices:" << endl;
			cin >> v >> w;
			PF::BFS(graph, v, w);
		}
		else if (input == "pf_early") {
			cout << "type the initial and final vertices:" << endl;
			cin >> v >> w;
			PF::BFSEarlyExit(graph, v, w);
		}
		else if (input == "dijkstra") {
			cout << "type the initial and final vertices" << endl;
			cin >> v >> w;
			PF::Dijkstra(graph, v, w);
		}
		else if (input == "astar") {
			cout << "type the initial and final vertices" << endl;
			cin >> v >> w;
			PF::AStar(graph, v, w);
}
		else if (input == "exit") {
			break;
		}
	}
	
	delete graph;

	return 0;
}