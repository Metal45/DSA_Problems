#include <iostream>
using namespace std;

void PrintSubArray(int arr[], int n, int ind){
    if(ind == n){
        return ;
    }

    for(int j = ind; j < n; j++){
        for(int k = ind; k <= j; k++){
            cout << arr[k] << " ";
        }
        cout << endl;
    } 

    PrintSubArray(arr, n, ind + 1);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    PrintSubArray(arr, n, 0);
}