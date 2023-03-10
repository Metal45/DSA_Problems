// An array is said to be nearly sorted if the elements in a normal sorted array at ith index can be found at either i - 1 or i or i + 1 index in the given array. 
// Search for a element in a nearly sorted array.

// Brute Force -> TC O(N) SC O(1) Linear Search 

// Efficient Approach -> Binary Search TC -> O(LogN) Since the array is nearl sorted some changes have to be made in the normal binary search algorithm 

#include <iostream>
using namespace std;

int nearlySorted(int arr[], int target, int n){
    int s = 0;
    int e = n - 1;

    while(s <= e){
        int mid = s + (e - s)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(mid + 1 < n &&arr[mid - 1] == target){
            return mid - 1;
        }
        else if(mid - 1 >= 0 && arr[mid + 1] == target){
            return mid + 1;
        }

        if(arr[mid] < target){
            s = mid + 2;
        }else{
            e = mid - 2;
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << nearlySorted(arr, target, n) << endl;
}

