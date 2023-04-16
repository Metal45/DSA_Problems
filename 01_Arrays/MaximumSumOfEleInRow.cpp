#include <bits/stdc++.h>
using namespace std;

int solve(int arr[3][3], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        int maxElement = INT_MIN;
        for(int j = 0; j < n; j++){
            int num = arr[i][j];
            if(num > maxElement){
                maxElement = num;
            }
        }
        sum += maxElement;
    }

    return sum;
}
int main(){
    int arr[3][3] = {{4, 6, 1},
                     {2, 5, 7},
                     {9, 1, 2}};
    cout << solve(arr, 3);
}