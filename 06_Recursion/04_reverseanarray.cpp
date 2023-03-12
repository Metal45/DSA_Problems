#include <iostream>
using namespace std;

void reverse(int arr[], int n){
    if(n <= 0){
        return;
    }
    
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;

    reverse(arr + 1, n - 2);
}

int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    
    cout << "Input Array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl; 


    reverse(arr, n);

    cout << "Output Array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl; 
   
}