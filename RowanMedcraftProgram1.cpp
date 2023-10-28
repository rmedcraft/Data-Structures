// Rowan Medcraft
// 9/29/2023
// rmedcraft@live.esu.edu
// Section 1
// calculates the runtime of various sorting algorithms
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void bubbleSort(int [], int);
void selectionSort(int [], int);
void insertionSort(int [], int, int);

void mergeSort(int [], int, int);
void merge(int [], int, int, int);

void quickSort(int [], int, int);
int partition(int [], int, int);
void sortFirstMiddleLast(int [], int, int, int);

void radixSort(int [], int, int);

void printArr(int [], int);
void swap(int [], int, int);
bool arrSorted(int [], int);

int main(){
    srand(time(NULL));

    // loops from 8 elements to 16384 elements
    for(int i = 3; i < 4; i++){ // i = 3; i < 15; i++
        
        int size = pow(2, i); // size = 2^i
        cout << "Array Size: " << size << endl;

        int arrays[6][size]; // stores each of the arrays for sorting
        // fill the array with random values
        for(int j = 0; j < size; j++){
            int random = rand();
            for(int s = 0; s < 6; s++){
                arrays[s][j] = random;
            }
        }

        // for timing each sort
        clock_t start;
        clock_t end;

        cout << "Original Array: ";
        printArr(arrays[0], size);

        cout << "Bubble Sorted Array: ";
        start = clock();
        bubbleSort(arrays[0], size);
        end = clock();
        printArr(arrays[0], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;

        cout << "Selection Sorted Array: ";
        start = clock();
        selectionSort(arrays[1], size);
        end = clock();
        printArr(arrays[1], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;

        cout << "Insertion Sorted Array: ";
        start = clock();
        insertionSort(arrays[2], 0, size - 1);
        end = clock();
        printArr(arrays[2], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;

        cout << "Merge Sorted Array: ";
        start = clock();
        mergeSort(arrays[3], 0, size - 1);
        end = clock();
        printArr(arrays[3], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;

        cout << "Quick Sorted Array: ";
        start = clock();
        quickSort(arrays[4], 0, size - 1);
        end = clock();
        printArr(arrays[4], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;

        cout << "Radix Sorted Array: ";
        start = clock();
        radixSort(arrays[5], size, 5);
        end = clock();
        printArr(arrays[5], size);
        cout << "This sort took " << (end - start) << " to finish." << endl;
        if(!arrSorted(arrays[5], size)){
            cout << "RADIX SORT DOESNT WORK DUMB BITCH" << endl;
        }
    }

    return 0;
}

void bubbleSort(int arr[], int size){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i + 1]){
                // swap the two elements
                swap(arr, i, i + 1);
                sorted = false;
            }
        }
    }
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        // find the index of the lowest value
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        // put the lowest value in index i
        swap(arr, min, i);
    }
}

void insertionSort(int arr[], int first, int last){
    for(int i = first + 1; i <= last; i++){
        for(int j = i; j > first; j--){
            if(arr[j] < arr[j - 1]){
                // move arr[j] back by 1
                swap(arr, j, j - 1);
            } else {
                break;
            }
        }
    }
}

void mergeSort(int arr[], int first, int last){
    if(last - first + 1 <= 10){
        insertionSort(arr, first, last);
    } else {
        int mid = first + (last - first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void merge(int arr[], int first, int mid, int last){
    int temp[last - first + 1];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = 0;
    while((first1 <= last1) && (first2 <= last2)){
        if(arr[first1] <= arr[first2]){
            temp[index] = arr[first1];
            first1++;
        } else {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
    }

    while(first1 <= last1){
        temp[index] = arr[first1];
        first1++;
        index++;
    }

    while(first2 <= last2){
        temp[index] = arr[first2];
        first2++;
        index++;
    }

    // copy temp array into the original array
    for(int i = 0; i <= last - first; i++){
        arr[first + i] = temp[i];
    }
}

void quickSort(int arr[], int first, int last){
    if(last - first + 1 <= 10){
        insertionSort(arr, first, last);
    } else {
        int pivotIndex = partition(arr, first, last);

        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

int partition(int arr[], int first, int last){
    int mid = first + (last - first) / 2;
    sortFirstMiddleLast(arr, first, mid, last);
    swap(arr, mid, last - 1);
    int pivotIndex = last - 1;
    int pivot = arr[pivotIndex];

    int left = first + 1;
    int right = last - 2;
    bool done = false;

    while(!done){
        while(arr[left] < pivot){
            left++;
        }
    
        while(arr[right] > pivot){
            right--;
        }
        
        if(left < right){
            swap(arr, left, right);
            left++;
            right--;
        } else {
            done = true;
        }
    }

    swap(arr, pivotIndex, left);
    pivotIndex = left;

    //int i = first + 1; // i is the index of the smaller element
    //for(int j = first + 1; j < last - 1; j++){
    //    if(arr[j] < pivot){
    //        swap(arr, i, j);
    //        i++;
    //    }
    //}
    //swap(arr, i + 1, pivotIndex);
    //pivotIndex = i + 1;

    return pivotIndex;
}

void sortFirstMiddleLast(int arr[], int first, int mid, int last){
    if(arr[first] > arr[mid]){
        swap(arr, first, mid);
    }
    if(arr[mid] > arr[last]){
        swap(arr, mid, last);
    }
    if(arr[first] > arr[mid]){
        swap(arr, first, mid);
    }
}

// n is the amount of values in the array, d is the max amount of digits found in any value
void radixSort(int arr[], int n, int d){
    for(int j = 0; j < d; j++){
        int groups[10][n] = {0};
        int ctArr[10] = {0}; // {0} initializes all elements to 0, which i thought was done automatically but i guess not?
        int div = pow(10, j);
        for(int i = 0; i < n; i++){
            int k = (arr[i] / div) % 10; // k is the digit you want to sort
            groups[k][ctArr[k]] = arr[i];
            ctArr[k]++;
        }
        // replace all items in arr with the elements in the groups
        int index = 0;
        for(int i = 0; i < 10; i++){
            for(int k = 0; k < ctArr[i]; k++){
                arr[index] = groups[i][k];
                index++;
            }
        }
    }
}

void printArr(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << endl;
}

void swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

bool arrSorted(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}