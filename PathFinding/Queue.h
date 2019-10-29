#pragma once
class Queue
{
	int initial;
	int last;
	int* queue;
	int size;
	int queue_size;

public:

	Queue(int size);

	~Queue();

	bool IsEmpty();
	bool IsFull();
	void Enqueue(int item);
	int Dequeue();
	void Draw();
};

