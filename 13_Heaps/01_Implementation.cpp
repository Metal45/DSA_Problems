#include <iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int heapsize;

    Heap(int Tsize){
        size = Tsize + 1;
        arr = new int[Tsize];
        heapsize = 0;
    }


    void insertKey(int val){
       
        if(heapsize >= size - 1){
            cout << "Overflow, heap is full" << endl;
            return ;
        }

        heapsize++;
        arr[heapsize] = val;
        int childIndex = heapsize;

        while(childIndex > 1){
            int parentIndex = childIndex/2;

            if(arr[childIndex] > arr[parentIndex]){
                swap(arr[childIndex], arr[parentIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }

        }
    }


    void deleteKey(){
        arr[1] = arr[heapsize];
        heapsize--;
        int i = 1;
        
        while(i < heapsize){
            int lchild = 2*i;
            int rchild = 2*i + 1;
            int largest = i;

            if(lchild < heapsize && arr[largest] < arr[lchild]){
                largest = lchild;
            }

            if(rchild < heapsize && arr[largest] < arr[rchild]){
                largest = rchild;
            }

            if(largest == i){
                return;
            }else{
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }
};


void heapify(int *arr, int heapsize, int i){
    int index = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;
    int largest = i;

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
    for(int i = size/2; i > 0; i--){ // n/2
        // logn
        heapify(arr, size, i);
    }
}


int main(){
    // Heap H1(6);
    // H1.insertKey(50);
    // H1.insertKey(30);
    // H1.insertKey(70);
    // H1.insertKey(40);
    // H1.insertKey(80);
    // H1.insertKey(100);
    // H1.insertKey(90);
    
    // for(int i = 1; i <= H1.heapsize; i++){
    //     cout << H1.arr[i] << " ";
    // }

    // cout << endl;
    // H1.deleteKey();
    // for(int i = 1; i <= H1.heapsize; i++){
    //     cout << H1.arr[i] << " ";
    // }

    int n;
    cin >> n;
    int *arr2 = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    
    for(int i = 1; i < n; i++){
        cout << arr2[i] << " ";
    }

    cout << endl;

    BuildHeap(arr2, n);

    for(int i = 1; i < n; i++){
        cout << arr2[i] << " ";
    }
}