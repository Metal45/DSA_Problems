// Search in an infinite array 

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

int unboundedSearch(int arr[], int x){
    if(arr[0] == x){
        return 0;
    }

    int i = 1, j = 2;

    while(arr[j] < x){
        i = j;
        j = j * 2;
    }

    return binarySearch(arr, i, j, x);
}

int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = i*2;
    }

    int x;
    cin >> x;

    int ans = unboundedSearch(arr, x);
    cout << ans << " " ;
    if(ans != 1){
        cout << arr[ans] << endl;
    }
}