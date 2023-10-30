#include <bits/stdc++.h>
using namespace std;

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

    int longestPalindromeSubseq(string s) {
        string s1 = s; 
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, -1));
        return solve(s1, s2, 0, 0, dp) - 1;
    }
};