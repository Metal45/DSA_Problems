#include <bits/stdc++.h>
#define ll long long
using namespace std;

// We use the concept of pascal traingle to find the ncr value
// ncr = n! / (r! * (n - r)!)

int main(){
    // ncr in this vector is stored as ncr[n][r]
    vector<vector<int>> ncr(1001, vector<int>(1001, 0));
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                ncr[i][j] = 1;
            } else {
                // ncr = n-1cr-1 + n-1cr
                ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            }
        }
    }
}