#include <iostream>
using namespace std;

// Insertion sort is performed in 4 parts

// 1. you store the value of current element 
// 2. you compare the element with the left elements until it is smaller than them
// 3. shift the elements to the right by 1 place and create the position for the curr element 
// 4. place the element on its correct place

void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){

        int curr = arr[i];
        int j = i - 1;

        while(j >= 0 && curr < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = curr;
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[10];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Input array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    InsertionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}