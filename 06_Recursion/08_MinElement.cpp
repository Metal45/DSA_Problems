#include <iostream>
using namespace std;

int minElement(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    
    int out = minElement(arr + 1, n - 1);

    return min(arr[0], out);
}

int minElement2(int arr[], int n, int i, int &mini){
    if(i >= n){
        return mini;
    }

    mini = min(arr[i], mini);

    return minElement2(arr, n, i + 1, mini);
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


    int ans = minElement(arr, n);
    int mini = INT_MAX;
    int ans2 = minElement2(arr, n, 0, mini);

   cout <<"Min in Array is: " << ans << " " << ans2 << endl;
}