#include "Queue.h"
#include <exception>
#include <iostream>
using namespace std;

Queue::Queue(int size_new) {

	size = size_new;

	queue = new int[size];

	initial = 0;
	last = 0;
	queue_size = 0;
}

Queue::~Queue() {
	delete[] queue;
}

bool Queue::IsEmpty() {
	return queue_size == 0;
}

bool Queue::IsFull() {
	return queue_size == size;
}

void Queue::Enqueue(int item) {
	
	if (!IsFull()) {
		queue_size++;
		queue[last] = item;
		last = (last + 1) % size;
	}
	else {
		throw exception();
	}
}

int Queue::Dequeue() {
	int item;
	
	if (!IsEmpty()) {
		queue_size--;
		item = queue[initial];
		initial = (initial + 1) % size;
		return item;
	}
	else {
		throw exception();
	}
}

void Queue::Draw() {
	int i, w;
	for (i = 0, w = initial; i < queue_size; i++, w++) {
		if (w == size) {
			w = 0;
		}
		cout << queue[w] << " ";
	}
	cout << endl;
}