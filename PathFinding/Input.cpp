#include <iostream>
#include "Input.h"
using namespace std;

pair<int*, int> AskSequence() {
	pair<int*, int> result;
	int i;
	cout << "what is the size of the sequence?" << endl;
	cin >> result.second;
	result.first = new int[result.second];
	cout << "now put the sequence" << endl;
	for (i = 0; i < result.second; i++) {
		cin >> result.first[i];
	}
	return result;
}