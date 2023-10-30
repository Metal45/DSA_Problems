#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int s, int e, vector<vector<int>> &dp) {

        if(s >= e) { 
            return 0;
        }

        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int minAns = INT_MAX;

        for(int i = s; i <= e; i++) {
            int lower = i + solve(s, i - 1, dp);
            int higher =  i + solve(i + 1, e, dp);

            minAns = min(minAns, max(lower, higher));
        }

        return dp[s][e] = minAns;
    }

    int bottomUp(int n) {
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));

        for(int s = n; s >= 1; s--) {
            for(int e = 1; e <= n; e++) {


                if(s >= e) {
                    continue ;
                }

                int ans = INT_MAX;

                for(int i = s; i <= e; i++) {
                    
                    int lower = i + dp[s][i - 1];
                    int higher = i + dp[i + 1][e];

                    ans = min(ans, max(lower, higher));
                }

                dp[s][e] = ans;
                
            }
            
        }

        return dp[1][n];
    }


    int getMoneyAmount(int n) {
        //vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        //return solve(1, n, dp);
        return bottomUp(n);
    }
};