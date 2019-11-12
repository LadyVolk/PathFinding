#pragma once
#include <iostream>
#include "GraphAdj.h"
using namespace std;
namespace PF {

	void BFS(GraphAdj* graph, int vi, int vf);
	void BFSEarlyExit(GraphAdj* graph, int vi, int vf);
	void Dijkstra(GraphAdj* graph, int vi, int vf);
	void AStar(GraphAdj* graph, int vi, int vf);
}