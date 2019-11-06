#pragma once
#include <utility>
using namespace std;
class GraphAdj
{
private:

	int V;
	int A;
	bool **Adj;
	int **Cost;
	pair<int, int > * Pos;

public:

	GraphAdj(int size);
	~GraphAdj();

	void InsertArc(int v, int w, int cost);
	void RemoveArc(int v, int w);
	void Draw();
	int GetArc();
	bool IsArc(int v, int w);
	int GetV();
	int GetInDegree(int v);
	int GetOutDegree(int v);
	int GetCost(int v, int w);
	void SetPos(int v, int x, int y);
	pair <int, int> GetPos(int v);
};

