#include <iostream>
using namespace std;

const int CAPACITY = 10;

void initTable(int []); 
void printTable(int []); 
int hashFunction(int); 
void hashInsert(int [], int);
bool keyOccurs(int [], int);

int main(){
    // initialize the hashmap
    cout << "Part 1: Hash Table" << endl;
    int hashmap[CAPACITY];
    initTable(hashmap);
    hashInsert(hashmap, 10);
    hashInsert(hashmap, 22);
    hashInsert(hashmap, 11);
    hashInsert(hashmap, 31);
    hashInsert(hashmap, 24);
    hashInsert(hashmap, 88);
    hashInsert(hashmap, 38);
    hashInsert(hashmap, 21);

    printTable(hashmap);

    cout << "\nPart 2: Checking numbers in the hash table" << endl;
    if(keyOccurs(hashmap, 11)){
        cout << "11 is found" << endl;
    } else {
        cout << "11 is not found" << endl;
    }

    if(keyOccurs(hashmap, 31)){
        cout << "31 is found" << endl;
    } else {
        cout << "31 is not found" << endl;
    }

    if(keyOccurs(hashmap, 23)){
        cout << "23 is found" << endl;
    } else {
        cout << "23 is not found" << endl;
    }

    system("pause");


    return 0;
}


void initTable(int data[]){
    for(int i = 0; i < CAPACITY; i++){
        data[i] = -1;
    }
}

void printTable(int data[]){
    for(int i = 0; i < CAPACITY - 1; i++){
        cout << data[i] << ", ";
    }
    cout << data[CAPACITY - 1] << endl;
}

int hashFunction(int key){
    return (key % CAPACITY);
}

void hashInsert(int data[], int key){
    for(int i = 0; i < CAPACITY; i++){
        if(data[((hashFunction(key)) + (0 * i) + (1 * i * i)) % CAPACITY] == -1){
            data[((hashFunction(key)) + (0 * i) + (1 * i * i)) % CAPACITY] = key;
            break;
        }
    }
}

bool keyOccurs(int data[], int searchKey){
    for(int i = 0; i < CAPACITY; i++){
        if(data[hashFunction(searchKey) + (0 * i) + (1 * i * i)] == searchKey){
            return true;
        } else if(data[hashFunction(searchKey) + (0 * i) + (1 * i * i)] == -1){
            return false;
        }
    }
    return false;
}