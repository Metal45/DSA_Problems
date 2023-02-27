#include <iostream>
#include <algorithm>
using namespace std;

// we use mid as si + (ei - si)/2 so that we can avoid interger overflow so that si + ei can not go out of the rage of limit of int

int BinarySearch(int arr[], int n, int x){
    int si = 0;
    int ei = n - 1;

    while(si <= ei){

        int mid = si + (ei - si)/2;
        
        if(arr[mid] == x){
            return mid;
        }

        else if(arr[mid] > x){
            ei = mid - 1;
        }

        else{
            si = mid + 1;
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

    int x;
    cin >> x;

// use the inbuilt fucntion again 
    int ans = BinarySearch(arr, n , x);
    int ans2 = binary_search(arr, arr + n, x);
    cout << ans << endl;
    cout << ans2 << endl;
} 