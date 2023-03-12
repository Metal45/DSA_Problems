#include <iostream>
using namespace std;

int maxElement(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    
    int out = maxElement(arr + 1, n - 1);

    return max(arr[0], out);
}

int maxElement2(int arr[], int n, int i, int &maxi){
    if(i >= n){
        return maxi;
    }

    maxi = max(arr[i], maxi);

    return maxElement2(arr, n, i + 1, maxi);
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


    int ans = maxElement(arr, n);
    int maxi = INT_MIN;
    int ans2 = maxElement2(arr, n, 0, maxi);

   cout <<"Max in Array is: " << ans << " " << ans2 <<  endl;
}