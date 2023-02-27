#include <iostream>
using namespace std;

// What is selection sort?
// It sorts the aarray by placing the minimum or maximum element at its right position in the array 
// for n elements the array is sorted in n - 1 rounds as the last element is already sorted
// Time Complexity:
    // -> For first round we do n - 1 and then n -2 and n -3 upto 1 
    // n - 1 + n -2 + n - 3 + .... + 2 + 1
    // O(N^2)
// Space Complexity: O(1)


void SelectionSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        int minInd = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        swap(arr[i], arr[minInd]);
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

    SelectionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}