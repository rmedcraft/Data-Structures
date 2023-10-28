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
   IndexEntry * left;
   IndexEntry * right;
};

void insert(IndexEntry *, int, int, string, string, double);
IndexEntry* treeSearch(IndexEntry *, int);
void printNode(IndexEntry *);

void print(priorityQueue, int);

int main()
{
	// part 1 starts here
	IndexEntry * root = new IndexEntry();

	ifstream file;
	file.open("accounts.dat");
	if(!file) {
		cout << "File could not be found" << endl;
		return 1;
	}
	// gets rid of the first line in the .dat file that we dont want to read
	string useless;
	getline(file, useless);
	
	// reads the data from the file into the BST
	int index, id;
	string first, last;
	double balance;
	while(file){
		file >> index >> id >> first >> last >> balance;
		insert(root, id, index, first, last, balance);
	}

	// prompts the user to enter an ID to search for
	cout << "Enter Account ID: ";
	int input;
	cin >> input;
	IndexEntry* foundNode = treeSearch(root, input);

	if(!foundNode){
		cout << "Matched record number is -1" << endl;
	} else {
		cout << "Matched record number is " << foundNode->recNum << endl;
	}
	cout << "Corresponding account record from the database file: " << endl;
	if(!foundNode){
		cout << "Account ID not in Data" << endl;
	} else {
		printNode(foundNode);
	}

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

void insert(IndexEntry * head, int id, int index, string fName, string lName, double bal){
    if(!head){
        head = new IndexEntry();
		head->acctID = id;
		head->recNum = index;
		head->fName = fName;
		head->lName = lName;
		head->bal = bal;
		head->left = NULL;
		head->right = NULL;
    } else if(id < head->acctID){
        insert(head->left, id, index, fName, lName, bal);
    } else {
        insert(head->right, id, index, fName, lName, bal);
    }
}

IndexEntry* treeSearch(IndexEntry * head, int key){
	if(!head || key == head->acctID){
		return head;
	}
	if(key < head->acctID){
		return treeSearch(head->left, key);
	}
	return treeSearch(head->right, key);
}

void printNode(IndexEntry * node){
	printf("%-12s%-12s%-12s%-12s%-12s\n", "Record#", "AccountID", "FirstName", "LastName", "Balance");
	printf("%-12d%-12d%-12s%-12s%-12f", node->recNum, node->acctID, node->fName, node->lName, node->bal);

}

void print(priorityQueue queue, int num){
	cout << "After inserting " << num << " priority queue has: " << endl;
	queue.printArray();
	cout << endl;
}