// isme aur quick sort me galti karte hai ache se karna

//  Heap Sort -> O(NlogN)
// You can sort an array by converting it into an heap, by doing that the root node will always be maximum

// steps to sort the array:
// 1. build heap from the array -> O(N)
// 2. swap root with last node -> O(1)
// 3. decrease the size of the heap and heapify first node -> O(LogN)
// 4. repeat it until size of heap is 1 -> O(N)

// doing so the last element in the array will always be the root which is largest so it will be sorted in ascending order

#include <iostream>
using namespace std;

void heapify(int *arr, int heapsize, int i){
    int index = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;
    int largest = index;

    if(lchild < heapsize && arr[largest] < arr[lchild]){
        largest = lchild;
    }

    if(rchild < heapsize && arr[largest] < arr[rchild]){
        largest = rchild;
    }

    if(largest == index){
        return;
    }else{
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, heapsize, index);
    }
}

void BuildHeap(int *arr, int size){
    for(int i = size/2; i > 0; i--){
        heapify(arr, size, i);
    }
}

void HeapSort(int *arr, int n){
    int i = n - 1;
    while(i != 1){
        swap(arr[i], arr[1]);
        n--;
        i--;
        heapify(arr, n, 1);
    }
}

int main(){
    int arr[] = {-1, 100, 50, 60, 140, -52, 1, 20, 30};
    BuildHeap(arr, 9);
    HeapSort(arr, 9);
    for(int i = 0; i < 9; i++){
        cout << arr[i] << " ";
    }
}