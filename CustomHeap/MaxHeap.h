//Elijah Turany
//CS244-002
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
		//Returns if index is already root
		if (index <= 0) {
			return;
		}
		//Returns if the parent (given by (index-1)/2) is bigger that the item at the given index
		if (data[(index - 1) / 2] >= data[index]) {
			return;
		}
		//Otherwise swaps the elements as the given index and it's parent, and calls reheapifyUp on the new parent
		else {
			HeapEntry tmp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = tmp;
			reheapifyUp((index - 1) / 2);
		}
	}

void reheapifyDown(int currentIndex) {
	//TODo
}

public:
	//Constructor
	MaxHeap() {}

	//Public Methods
	void enqueue(HeapEntry x) {
		//Push new element into array and call reheapifyUp on that index
		data.push_back(x);
		//Since index starts at 0, reheapifyUp is called on size instead of size + 1
		reheapifyUp(size);
		size++;
	}

	HeapEntry peek() {
		return HeapEntry("replaceme", 0);
	}

	HeapEntry dequeue() {
		return HeapEntry("replaceme", 0);
	}

	int getSize() { return size; }

	//Helper function for testing - display the entire heap in index order
	void print() {
		cout << "-----\n";
		for (int i = 0; i < data.size(); i++) {
			cout << i << " : " << data[i].priority << " " << data[i].data << endl;
		}
		cout << "-----\n";
	}

	//Helper function for testing - return the data vector
	vector<HeapEntry> reportData() {
		return data;
	}

};