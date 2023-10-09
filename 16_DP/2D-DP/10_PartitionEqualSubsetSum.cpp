#include <bits/stdc++.h>
using namespace std;

// Approach -> since we have two make two subsets such that there sum is equal so we check if ther exists a subset 
// whose sum is half the total sum of the array if yes then there are two subsests that have equsl sum 


class Solution {
public:
    bool topdown1(vector<int> &nums, int ind, int n, int sum, int capacity, vector<vector<int>> &dp){
        if(ind >= n){
            return false;
        }

        if(sum == capacity){
            return true;
        }

        if(dp[ind][capacity] != -1){
            return dp[ind][capacity];
        }

        bool include = solve(nums, ind + 1, n, sum + nums[ind], capacity - nums[ind], dp);
        bool exclude = solve(nums, ind + 1, n, sum, capacity, dp);
        
        return dp[ind][capacity] = include || exclude;
    }


    bool topdown2(vector<int> &nums, int ind, int n, int target, vector<vector<int>> &dp){
        if(ind >= n) {
            return 0;
        }

        if(target < 0) {
            return 0;
        }

        if(target == 0) {
            return 1;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        bool inc = solve2(nums, ind + 1, n, target - nums[ind], dp);
        bool exc = solve2(nums, ind + 1, n, target, dp);

        return dp[ind][target] = inc || exc;
    }

    bool bottomup2(vector<int> &nums, int n, int target){
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));

        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int t = 1; t <= target; t++){

                bool inc = 0;
                if(t - nums[i] >= 0){
                    inc = dp[i + 1][t - nums[i]];
                }
                bool exc = dp[i + 1][t];

                dp[i][t] = inc || exc;
            }
        }

        return dp[0][target];
    }


    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int capacity = accumulate(nums.begin(), nums.end(), 0);

        if(capacity & 1) {
            return false;
        }
        int target = capacity/2;
        //vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        //bool ans = topdown2(nums, 0, n, target, dp);

        bool ans = bottomup2(nums, n, target);
        return ans; 
    }
};