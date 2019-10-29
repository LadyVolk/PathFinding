#pragma once
#include "GraphAdj.h"

GraphAdj* RandomGraph1(int v, int a);
GraphAdj* RandomGraph2(int v, int a);

bool CheckWalk(GraphAdj* graph, int seq[], int seq_size);
bool CheckPath(GraphAdj* graph, int seq[], int seq_size);
bool CheckSimplePath(GraphAdj* graph, int seq[], int seq_size);
bool CheckCycle(GraphAdj* graph, int seq[], int seq_size);
bool CheckSimpleCycle(GraphAdj* graph, int seq[], int seq_size);
GraphAdj* RemoveV(GraphAdj* graph_old, int vertex);
bool IsTopological(GraphAdj* graph);
bool Reach(GraphAdj* graph, int vi, int vf);
void visit_adj(GraphAdj* graph, int v, bool* visited);
void BFS(GraphAdj* graph, int initial, int* num, int* parent);