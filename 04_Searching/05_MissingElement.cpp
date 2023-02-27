// Find the missing element in a given sorted array with numbers of 1 to N-1 and all unique
#include <iostream>
using namespace std;


// Brute Force -> Linear Search , XOR, sum  ->  TC O(N) SC O(1)

// Efficient -> Binary Search TC O(LogN) SC O(1)
// Approach -> if there is no missing element till now the difference in the index and the number is one so you have to search right but if there is a missing elemnt 
// the differnce is 2 then you have to search in the left array. So at end s will end at the next index off missing element

int FindMissingElement(int arr[], int n){
    int s = 0;
    int e = n - 1;
    while(s < e){
        int mid = s + (e - s)/2;

        if(arr[s] - s == 1){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return arr[s] - 1;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = FindMissingElement(arr, n);
    cout << ans << endl;
}