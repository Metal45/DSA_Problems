#include <iostream>
using namespace std;

int binarySearch(int arr[], int si, int ei, int x){

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

int exponentialSearch(int arr[], int n, int x){
    if(arr[0] == x){
        return 0;
    }
    int i = 1;
    while(i < n && arr[i] <= x){
        i = i * 2;
    }
    return binarySearch(arr, i/2, min(i, n - 1), x);
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

    int ans = exponentialSearch(arr, n, x);
    cout << ans << " " ;
    if(ans != 1){
        cout << arr[ans] << endl;
    }
}