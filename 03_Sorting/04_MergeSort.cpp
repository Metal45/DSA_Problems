#include <iostream>
using namespace std;

void merge2(int *arr, int s, int e){
    int mid = s + (e - s)/2;

    int n = e - s + 1;
    int *merged = new int[n];
   
    int leftIndex = s, rightIndex = mid + 1;
    int mainIndex = 0;

    while(leftIndex <= mid && rightIndex <= e){
        if(arr[leftIndex] < arr[rightIndex]){
            merged[mainIndex++] = arr[leftIndex++];
        }else{
            merged[mainIndex++] = arr[rightIndex++];
        }
    }

    while(leftIndex <= mid){
        merged[mainIndex++] = arr[leftIndex++];
    }

    while(rightIndex <= e){
        merged[mainIndex++] = arr[rightIndex++];
    }

    mainIndex = 0;
    for(int i = s; i <= e; i++){
        arr[i] = merged[mainIndex++];
    }

    delete []merged;
}

void merge(int *arr, int s, int e){
    int mid = s + (e - s)/2;
    
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *left = new int[l1];
    int *right = new int[l2];

    int k = s;
    for(int i = 0; i < l1; i++){
        left[i] = arr[k];
        k++;
    }
    
    for(int i = 0; i < l2; i++){
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0, rightIndex = 0;
    int mainIndex = s;

    while(leftIndex < l1 && rightIndex < l2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainIndex++] = left[leftIndex++];
        }else{
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex < l1){
        arr[mainIndex++] = left[leftIndex++];
    }

    while(leftIndex < l1){
        arr[mainIndex++] = right[rightIndex++];
    }

    delete []left;
    delete []right;
}

void mergeSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }

    int mid = s + (e - s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge2(arr , s, e);
};

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n -1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}