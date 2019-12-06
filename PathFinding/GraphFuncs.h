#pragma once
#include "GraphAdj.h"

GraphAdj* RandomGraph1(int v, int a);
GraphAdj* RandomGraph2(int v, int a);
GraphAdj* GridGraph(int width, int height);
GraphAdj* RandomGrid(int walls, int width, int height);
GraphAdj* RemoveV(GraphAdj* graph_old, int vertex);

bool CheckWalk(GraphAdj* graph, int seq[], int seq_size);
bool CheckPath(GraphAdj* graph, int seq[], int seq_size);
bool CheckSimplePath(GraphAdj* graph, int seq[], int seq_size);
bool CheckCycle(GraphAdj* graph, int seq[], int seq_size);
bool CheckSimpleCycle(GraphAdj* graph, int seq[], int seq_size);
bool IsTopological(GraphAdj* graph);
bool Reach(GraphAdj* graph, int vi, int vf);
void visit_adj(GraphAdj* graph, int v, bool* visited);
void PreBFS(GraphAdj* graph, int initial, int* num, int* parent);
void PreBFSEarlyExit(GraphAdj* graph, int initial, int* num, int* parent, int vf);
void PreDijkstra(GraphAdj* graph, int initial, int* parent, int vf);
void CreateWall(GraphAdj* grid, int v, int width, int height);
void PreAStar(GraphAdj* graph, int initial, int* parent, int vf);
