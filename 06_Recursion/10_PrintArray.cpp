#include <iostream>
using namespace std;

void print(int arr[], int n){
    if(n == 1){
        cout << arr[0] << endl;
        return;
    }
    
    cout << arr[0] << " ";

    print(arr + 1, n - 1);
    
    
}


void print2(int arr[], int n, int i){
    if(i >= n){
        cout << endl;
        return;
    }

    cout << arr[i] << " ";

    print2(arr, n, i + 1);
}


int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    
    cout << "Input Array: ";

    print(arr, n);
    print2(arr, n, 0);
}