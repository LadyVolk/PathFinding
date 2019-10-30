#include "PriorityQueue.h"
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node
{
	int v;
	int cost;
	struct Node *next;
};


PriorityQueue::PriorityQueue() {
	front = NULL;
}
PriorityQueue::~PriorityQueue() {
	while (!IsEmpty()) {
		Dequeue();
	}
}
void PriorityQueue::Enqueue(int v, int cost) {
	Node *new_node = new Node;
	Node *now_node;
	new_node->v = v;
	new_node->cost = cost;
	if (IsEmpty() || new_node->cost < front->cost) {
		new_node->next = front;
		front = new_node;
	}
	else {
		now_node = front;
		while (now_node->next != NULL &&
			   new_node->cost >= now_node->next->cost) {
			now_node = now_node->next;
		}
		new_node->next = now_node->next;
		now_node->next = new_node;
	}
	
}
bool PriorityQueue::IsEmpty() {
	return front == NULL;
}
int PriorityQueue::Dequeue() {
	Node *for_removal;
	int v;
	if (!IsEmpty()) {
		for_removal = front;
		v = for_removal->v;
		front = front->next;
		delete for_removal;
		return v;
	}
	else {
		cout << "queue is empty" << endl;
		return -1;
	}
}
void PriorityQueue::Draw() {
	Node *now_node;
	if (IsEmpty()) {
		cout << "queue is empty" << endl;
	}
	else {
		now_node = front;
		while (now_node) {
			cout << now_node->v << "(" << now_node->cost << ") ";
			now_node = now_node->next;
		}
		cout << endl;
	}
}
