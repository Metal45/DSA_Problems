#include <bits/stdc++.h>
using namespace std;

// Memoization will give TLE if you don't pass string by reference in the function call 

class Solution {
public:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        if(i > text1.size() || j > text2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
        }else {
            return dp[i][j] = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
        }
    }

    int bottomUp(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(text1[i] == text2[j]){
                    curr[j] = 1 + next[j + 1];
                }else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }

            next = curr;
        }

        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, -1));
        return solve(text1, text2, 0, 0, dp) - 1;
        //return bottomUp(text1, text2);
    }
};