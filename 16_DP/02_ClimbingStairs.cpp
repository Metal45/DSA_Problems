#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int topDownSolve(int n, vector<int> &dp){
        if(n == 1 || n == 2) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }

    int bottomUpSolve(int n){
        vector<int> dp(n + 1, -1);

        dp[1] = 1;
        if(n == 1){
            return dp[1];
        }

        dp[2] = 2;
        if(n == 2){
            return dp[2];
        }

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int spaceOptimized(int n){
        int prev2 = 2;
        int prev1 = 1;
        if(n == 1){
            return prev1;
        }

        if(n == 2){
            return prev2;
        }

        int currStair = 0;
        for(int i = 3; i <= n; i++){
            currStair = prev1 + prev2;
            prev1 = prev2;
            prev2 = currStair;
        }

        return currStair;
    }

    int climbStairs(int n){
        vector<int> dp(n+1,-1);
        return spaceOptimized(n);
    }
};