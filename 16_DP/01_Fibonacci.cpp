#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // linear space time
    int topDownSolve(int n, vector<int> &dp){
        // goes from n -> 2
        if(n == 0 || n == 1) return n;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
        return dp[n];
    }


    // linear space time
    int bottomUpSolve(int n, vector<int> &dp){
        // goes from 2 -> n
        dp[0] = 0;
        if(n == 0) return 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }

    // space optimization
    // linear with constant space
    int spaceSolve(int n){
        int prev2 = 0;
        int prev1 = 1;

        int curr = 0;
        for(int i = 2; i <= n; i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return spaceSolve(n);
    }
};