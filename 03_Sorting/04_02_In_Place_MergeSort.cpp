#include <bits/stdc++.h> 
// Learn the method 1 also -> 

// TC -> O(N*logN*logN)
void merge(vector<int> &arr, int s, int mid, int e){
    int size = e - s + 1;
    int gap = (size/2) + (size % 2);

    while(gap > 0){
        int i = s, j = s + gap;
        while(j <= e){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }

        if(gap == 1){
            break;
        }else{
            gap = (gap/2) + (gap % 2);
        }
    }
}

void mergeSort(vector<int> &arr, int s, int e){
    
    if(s >= e){
        return;
    }

    int mid = s + (e - s)/2;
    // log N
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // NLogN
    merge(arr, s, mid, e);
}

vector<int> mergeSort(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
}