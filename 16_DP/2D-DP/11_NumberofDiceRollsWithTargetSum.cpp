#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int topDown(int n, int k, int target, vector<vector<int>> &dp){
        if(target < 0) {
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0) {
            return 0;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;

        for(int i = 1; i <= k; i++){
            ans = (ans + (topDown(n - 1, k, target - i, dp)) % mod) % mod;
        }

        return dp[n][target] = ans;
    }

    int bottomUp(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                int ans = 0;

                for(int x = 1; x <= k; x++){
                    if(j - x >= 0)
                    ans = (ans + dp[i - 1][j - x]) % mod;
                }

                dp[i][j] = ans;
            }
        }

        return dp[n][target];
    }

    int bottomUpSO(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                int ans = 0;

                for(int x = 1; x <= k; x++){
                    if(j - x >= 0)
                    ans = (ans + prev[j - x]) % mod;
                }

                curr[j] = ans;
            }
            
            // yaha galti hogi loop ke bahaar prev ko curr karna hai 
            prev = curr;
        }

        return prev[target];
    }


    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        //return topDown(n, k, target, dp);
        return bottomUpSO(n, k, target);
    }
};