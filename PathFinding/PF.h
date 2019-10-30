#pragma once
#include <iostream>
#include "GraphAdj.h"
using namespace std;
namespace PF {

	void BFS(GraphAdj* graph, int vi, int vf);
	void BFSEarlyExit(GraphAdj* graph, int vi, int vf);
}