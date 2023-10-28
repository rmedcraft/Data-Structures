// Rowan Medcraft
// 10/28/2023
// rmedcraft@live.esu.edu
// Section 1
// Demonstrates the functions of a Binary Search Tree and a Priority Queue

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>
using namespace std;

struct IndexEntry
{
   int acctID;   // (key) Account identifier
   long recNum;  // Record number
   string fName;
   string lName;
   double bal;
};

void print(priorityQueue, int);
int main()
{
	// part 1 here
	fstream file;
	file.open("accounts.dat", ios::in);
	// part 2 starts here
	priorityQueue myqueue;

	if (myqueue.empty())
		cout << "My priority Queue is empty\n" << endl;

	myqueue.insert(59);
	print(myqueue, 59);

	myqueue.insert(41);
	print(myqueue, 41);

	myqueue.insert(25);
	print(myqueue, 25);

	myqueue.insert(12);
	print(myqueue, 12);

	myqueue.insert(91);
	print(myqueue, 91);

	myqueue.min(); // this line of code does absolutely nothing but it was in the driver file so I'm keeping it
	myqueue.extractMin();
	cout << "After extracting the minimum value, the priority queue has: " << endl;
	myqueue.printArray();
	cout << endl;

	myqueue.insert(34);
	print(myqueue, 34);

	myqueue.insert(63);
	print(myqueue, 63);

	myqueue.extractMin();
	cout << "After extracting the minimum value, the priority queue has: " << endl;
	myqueue.printArray();
	cout << endl;

	myqueue.insert(75);
	print(myqueue, 75);

	myqueue.insert(85);
	print(myqueue, 85);

	myqueue.extractMin();
	cout << "After extracting the minimum value, the priority queue has: " << endl;
	myqueue.printArray();
	cout << endl;

	cout << "Minimum value is ";
	cout << myqueue.min() << endl;

	system("pause");
	return 0;
}

void print(priorityQueue queue, int num){
	cout << "After inserting " << num << " priority queue has: " << endl;
	queue.printArray();
	cout << endl;
}