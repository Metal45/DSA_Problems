#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int x){

    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
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

    int ans = LinearSearch(arr, n , x);
    cout << ans << endl;
}