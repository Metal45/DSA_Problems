#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // rec +  memoization -> TLE + MLE
    int solve(vector<int> &arr, int diff, int curr, int prev, vector<vector<int>> &dp) {
        if(curr >= arr.size()) {
            return 0;
        }

        if(dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }
 
        int take = INT_MIN;
        if(prev == -1 || arr[curr] - arr[prev] == diff) {
            int take = 1 + solve(arr, diff, curr + 1, curr, dp);
        }

        int notTake = solve(arr, diff, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(take, notTake);
    }

    // tabulation -> TLE + MLE
    int solveUsingTab(vector<int> &nums, int k) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, 0));
        
        for(int curr = nums.size() - 1; curr >= 0; curr--) {
            for(int prev = nums.size() - 1; prev >= -1; prev--) {
               
                if(prev >= curr) {
                    continue;
                }

                int take = 0;
                
                if(prev == -1 || nums[curr] - nums[prev] == k) {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                int notTake = dp[curr + 1][prev + 1];
                
                dp[curr][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    // space Optimised tabulation -> TLE 
    int tabSO(vector<int> &nums, int k) {
        vector<int> currRow(nums.size() + 1, 0);
        vector<int> nextRow(nums.size() + 1, 0);
        
        for(int curr = nums.size() - 1; curr >= 0; curr--) {
            for(int prev = nums.size() - 1; prev >= -1; prev--) {
               
                if(prev >= curr) {
                    continue;
                }

                int take = 0;
                
                if(prev == -1 || nums[curr] - nums[prev] == k) {
                    take = 1 + nextRow[curr + 1];
                }

                int notTake = nextRow[prev + 1];
                
                currRow[prev + 1] = max(take, notTake);
            }

            nextRow = currRow;
        }

        return nextRow[0];
    }
    
    // tabulation + hashing 0 - > n - 1 
    int tabHash(vector<int> &arr, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i] - k) != mp.end()) {
                mp[arr[i]] = 1 + mp[arr[i] - k];
            }else{
                mp[arr[i]] = 1;
            }

        }

        int maxi = INT_MIN;
        for(auto i : mp) {
            maxi = max(maxi, i.second);
        }

        return maxi;
    }

    // tabulation + hashing n - 1 -> 0
    int tabHash2(vector<int> &arr, int k) {
        unordered_map<int, int> mp;

        for(int i = arr.size() - 1; i >= 0; i--) {
            if(mp.find(k + arr[i]) != mp.end()) {
                mp[arr[i]] = 1 + mp[k + arr[i]];
            }else{
                mp[arr[i]] = 1;
            }

        }

        int maxi = INT_MIN;
        for(auto i : mp) {
            maxi = max(maxi, i.second);
        }

        return maxi;
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        // int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return solve(arr, difference, 0, -1, dp);
        // return solveUsingTab(arr, difference);
        // return tabSO(arr, difference);
        // return tabHash(arr, difference);
        return tabHash(arr, difference);
    }
};