using namespace std;
#include "MaxHeap.h"
#include <iostream>

int main() {
	MaxHeap m;
	m.print();
	HeapEntry a("first", 6);
	m.enqueue(a);
	m.print();
	HeapEntry b("second", 1);
	m.enqueue(b);
	m.print();
	HeapEntry c("third", 7);
	m.enqueue(c);
	m.print();
	HeapEntry d("fourth", 0);
	m.enqueue(d);
	m.print();
}