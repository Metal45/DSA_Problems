#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        if(i >= word1.size()) {
            if(j >= word2.size()) {
                return 0;
            }else {
                return word2.size() - j; 
            }
        }

        if(j >= word2.size()) {
            if(i >= word1.size()) {
                return 0;
            }else {
                return word1.size() - i; 
            }
        },

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = solve(word1, word2, i + 1, j + 1, dp);
        }else {
            int replace = 1 + solve(word1, word2, i + 1, j + 1, dp);
            int dlt = 1 + solve(word1, word2, i + 1, j, dp);
            int insert = 1 + solve(word1, word2, i, j + 1, dp);

            ans = min(replace, min(dlt, insert));
        }

        return dp[i][j] = ans;
    }

    int bottomUp(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));

        for(int i = 0; i <= word1.size(); i++) {
            dp[i][word2.size()] = word1.size() - i;
        }

        for(int j = 0; j <= word2.size(); j++) {
            dp[word1.size()][j] = word2.size() - j;
        }

        for(int i = word1.size() - 1; i >= 0 ; i--) {
            for(int j = word2.size() - 1; j >= 0 ; j--) {
                int ans = 0;
                if(word1[i] == word2[j]) {
                    ans = dp[i + 1][j + 1];
                }else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int dlt = 1 + dp[i + 1][j];
                    int insert = 1 +  dp[i][j + 1];

                    ans = min(replace, min(dlt, insert));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    } 

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        //return solve(word1, word2, 0, 0, dp);
        return bottomUp(word1, word2);
    }
};