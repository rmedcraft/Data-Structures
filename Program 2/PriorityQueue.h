#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>

class priorityQueue
{
private:
	int size;
	int *data;

public:
	static const int CAPACITY = 50;
	priorityQueue(){ //constructor
		size = 0;
		data = new int[CAPACITY];
	}

	~priorityQueue() { }//destructor

	int getParent(int index){
		return (index - 1) / 2;
	}

	int getLeftChild(int index){
		return index * 2 + 1;
	}

	int getRightChild(int index){
		return index * 2 + 2;
	}

	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}

	void insert(int item){
		int i = size++; // size is incremented after i is set
		while(i > 0 && data[getParent(i)] > item){ // > for min heap
			data[i] = data[getParent(i)];
			i = getParent(i);
		}
		data[i] = item;
	} 

	void printArray(){
		for(int i = 0; i < size - 1; i++){
			std::cout << data[i] << ", ";
		}
		std::cout << data[size - 1] << std::endl;
	}
	void heapify(int index){
		int left = getLeftChild(index);
		int right = getRightChild(index);
		int smallest = index; // smallest for min heap
		if(left < size && data[left] < data[index]){
			smallest = left;
		}
		if(right < size && data[right] < data[smallest]){
			smallest = right;
		}
		if(smallest != index){
			swap(data[smallest], data[index]);
			heapify(smallest);
		}
	}

	//remove and return the smallest item currently in the priority queue
	int extractMin(){
		int min = data[0];
		data[0] = data[size - 1];
		size--;
		heapify(0);
		return min;
	}
	bool empty() const{
		return size == 0;
	}
	int min() const{  //return the smallest item
		return data[0];
	}
};

#endif