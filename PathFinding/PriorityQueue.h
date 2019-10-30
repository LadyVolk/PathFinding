#pragma once
class PriorityQueue
{
	struct Node *front;
public:

	PriorityQueue();
	~PriorityQueue();

	void Enqueue(int v, int cost);
	bool IsEmpty();
	int Dequeue();
	void Draw();
};

