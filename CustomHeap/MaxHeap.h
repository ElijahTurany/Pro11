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
	void reheapifyUp(int currentIndex) {
		//TODO
	}

	void reheapifyDown(int currentIndex) {
		//TODo
	}

public:
	//Constructor
	MaxHeap() {
		data.push_back(HeapEntry("", 0)); //Place a blank entry into index 0 in the vector.
		// Recall that we put the root in index 1!
	}

	//Public Methods
	void enqueue(HeapEntry x) {
		//TODO
	}

	HeapEntry peek() {
		//TODO
		return HeapEntry("replaceme", 0);
	}

	HeapEntry dequeue() {
		//TODO
		return HeapEntry("replaceme", 0);
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