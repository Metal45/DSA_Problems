#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int i, int key){
    if(i >= n){
        return -1;
    }

    if(arr[i] == key){
        return i;
    }

    return linearSearch(arr, n, i + 1, key);
}

int linearSearch2(int arr[], int n, int key){
    if(n == 0){
        return -1;
    }

    if(arr[0] == key){
        return n;
    }

    return linearSearch2(arr + 1, n - 1, key);
}


int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int ans = linearSearch(arr, n, 0, key);
    int ans2 = n - linearSearch2(arr, n, key);
    
    cout << "index: " << ans <<" "<< ans2 << endl;
}