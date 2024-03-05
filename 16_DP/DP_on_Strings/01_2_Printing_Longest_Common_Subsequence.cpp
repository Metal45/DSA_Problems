#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i >= n || j >= m) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] =  1 + solve(i + 1, j + 1, n, m, s1, s2, dp);
        }else {
            return dp[i][j] = max(solve(i + 1, j, n, m, s1, s2, dp), solve(i, j + 1, n, m, s1, s2, dp));
        }
    }

    int bottomUp(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] =  1 + dp[i+1][j+1];
                }else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        // Printing the longest common subsequence using the dp table
        int i = 0, j = 0;
        string s = "";

        while(i < n && j < m) {
            if(s1[i] == s2[j]) {
                s += s1[i];
                i++;
                j++;
            }else {
                if(dp[i+1][j] < dp[i][j+1]) {
                    j++;
                }else {
                    i++;
                }
            }
        }

        cout << s << endl;

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size(), m = text2.size();
        // int i = 0, j = 0;
        // vector<vector<int>> dp(n, vector<int> (m, -1));

        // int ans = solve(i, j, n, m, text1, text2, dp);

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << dp[i][j] << "   ";
        //     }
        //     cout << endl;
        // }

        int ans = bottomUp(text1, text2);
        return ans;
    }
};