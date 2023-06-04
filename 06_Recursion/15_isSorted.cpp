#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int i, int prev){
    if(i >= n){
        return true;
    }

    int curr = arr[i];
    cout << prev << " " << curr << endl;

    if(curr < prev){
        return false;
    }
    
    return isSorted(arr, n, i + 1, curr);  
}

bool isSorted2(int arr[], int n, int i){
    if(i == n - 1){
        return true;
    }

    if(arr[i + 1] < arr[i]){
        return false;
    }

    return isSorted2(arr, n, i + 1);
}

bool isSorted3(int arr[], int n){
    if(n == 1 || n == 0){
        cout << endl;
        return true;
    }

    cout << arr[0] << " " << arr[1] << endl; 
    if(arr[1] < arr[0]){
        return false;
    }

    return isSorted3(arr + 1, n - 1);
}

int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << isSorted2(arr, n, 0) << endl; 
}