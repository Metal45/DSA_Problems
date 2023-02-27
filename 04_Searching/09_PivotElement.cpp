// Find the pivot element in an array
#include <iostream>
using namespace std;

// Approach -> TC O(LogN) SC O(1)
// A element about which a sorted array has been rotated can be called as a pivot element so the all the elements before and after the pivot will be in sorted order 
// but the pivot is the breaking point between them. From here it is clear that we can apply binary search in this question.

// -> condition for returning 
// property of left   ->    (mid - 1 < mid)
// property of right  ->    (mid < mid + 1) 
// compare mid with previous and next, if the array is sorted in increasing order the pivot will be greater than it previous as well as next element in the array while all other element will be greater than the previous and smaller than the next one 

// -> condition for searching 
// you will compare mid from starting element if starting element is smaller than the mid it shows you are in the left part and peak is at right
// and if the starting element is largerer than the mid it shows you are in right part you the peak will be in the left
// it will become more clear once you see it in diagramatic representation

// Note: Edge Case Do not do s <= e as for single element it might throw some error so as of single element that itself is the pivot. we will only come out of loop in two cases
// is no pivot or a single element in both cases we return the starting element

int pivotElement(int arr[], int n){
    int s = 0, e = n - 1;

    while(s < e){
        int mid = s + (e - s)/2;

        // comparing with next
        if(mid + 1 < e && arr[mid] > arr[mid + 1]){
            return mid;
        }

        // since mid is not pivot checking if prev is pivot 
        if(mid - 1 >= s && arr[mid - 1] > arr[mid]){
            return mid - 1;
        }

        if(arr[s] > arr[mid]){
            e = mid - 1;
        }else if(arr[s] <= arr[mid]){
            s = mid + 1;
        }
    }

    return s;
}


int main(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << pivotElement(arr, n) << endl;
}