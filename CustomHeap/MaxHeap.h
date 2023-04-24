#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Some heaps are used to manage items whose value is separate from their priority.
//This helper class allows us to directly compare "HeapEntry" items by comparing
// their priorities.
//Note the fields are public. This class is effectively a "pair".
class HeapEntry {
public:
	//Fields
	string data;
	int priority;

	//Constructor
	HeapEntry(string d, int p) {
		data = d;
		priority = p;
	}

	//Operator overloads
	bool operator<(const HeapEntry& other) {
		return priority < other.priority;
	}
	bool operator>(const HeapEntry& other) {
		return priority > other.priority;
	}
	bool operator==(const HeapEntry& other) {
		return priority == other.priority;
	}
	bool operator<=(const HeapEntry& other) {
		return priority <= other.priority;
	}
	bool operator>=(const HeapEntry& other) {
		return priority >= other.priority;
	}
};

class MaxHeap {
private:
	//Fields
	vector<HeapEntry> data;
	int size{ 0 }; //Number of items stored
	int capacity{ 0 }; //Number of items that can be stored without expanding the vector.

	//Private helper methods
	void reheapifyUp(int index) {
		if (index <= 0) {
			return;
		}
		if (data[(index - 1) / 2] >= data[index]) {
			return;
		}
		else {
			HeapEntry tmp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = tmp;
			reheapifyUp((index - 1) / 2);
		}
	}

	void reheapifyDown(int index) {
		if ((((index + 1) * 2) - 1) >= size) { return; }
		if ((data[index] >= data[((index + 1) * 2) - 1]) && (data[index] >= data[(index + 1) * 2])) { return; }
		if ((((index + 1) * 2) - 1) == size - 1) {
			if (data[index] < data[((index + 1) * 2) - 1]) {
				HeapEntry tmp = data[index];
				data[index] = data[((index + 1) * 2) - 1];
				data[((index + 1) * 2) - 1] = tmp;
			}
			return;
		}

		if (data[((index + 1) * 2) - 1] >= data[(index + 1)* 2]) {
			HeapEntry tmp = data[index];
			data[index] = data[((index + 1) * 2) - 1];
			data[((index + 1) * 2) - 1] = tmp;
			reheapifyDown(((index + 1) * 2) - 1);
		}
		else {
			HeapEntry tmp = data[index];
			data[index] = data[(index + 1) * 2];
			data[(index + 1) * 2] = tmp;
			reheapifyDown((index + 1) * 2);
		}
	}

public:
	//Constructor
	MaxHeap() {}

	//Public Methods
	void enqueue(HeapEntry x) {
		data[size] = x;
		reheapifyUp(size);
		size++;
	}

	HeapEntry peek() {
		return data[0];
	}

	HeapEntry dequeue() {
		HeapEntry returnMe = data[0];
		data[0] = data[size];
		size--;
		reheapifyDown(0);
		return returnMe;
	}

	int getSize() { return size; }

	//Helper function for testing - display the entire heap in index order
	void print() {
		cout << "-----\n";
		for (int i = 1; i < data.size(); i++) {
			cout << i << " : " << data[i].priority << " " << data[i].data << endl;
		}
		cout << "-----\n";
	}

	//Helper function for testing - return the data vector
	vector<HeapEntry> reportData() {
		return data;
	}

};