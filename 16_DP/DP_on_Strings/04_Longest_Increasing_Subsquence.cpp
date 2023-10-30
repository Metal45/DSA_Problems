#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp) {
        if(i >= nums.size()) {
            return 0;
        }

        // we will do prev + 1 instead of prev as one possible value of prev is -1 which 
        // is not a valid index so we will shift column that is prev by 1 so that -1 becoes 0
        // but make sure ther is no issue in size
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        int notTake = solve(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int solveUsingTab(vector<int> &nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, 0));
        
        for(int curr = nums.size() - 1; curr >= 0; curr--) {
            for(int prev = nums.size() - 1; prev >= -1; prev--) {
                // prev index always has to be less than the current index
                if(prev >= curr) {
                    continue;
                }

                int take = 0;
                // we will increase prev -> prev + 1 every where as -1 is also a possible value for prev
                // but while comparing we will compare curr to prev not prev + 1 as we are storing prev + 1 for prev in dp vector
                // but when we check in array we have to check for the element at prev index not prev + 1, so we handle prev == -1 seperately
                if(prev == -1 || nums[curr] > nums[prev]) {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                int notTake = dp[curr + 1][prev + 1];
                
                dp[curr][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    int spaceOptimised(vector<int> &nums) {
        vector<int> nextRow(nums.size() + 1, 0);
        vector<int> currRow(nums.size() + 1, 0);
        
        for(int curr = nums.size() - 1; curr >= 0; curr--) {
            for(int prev = nums.size() - 1; prev >= -1; prev--) {
                if(prev >= curr) {
                    continue;
                }

                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    take = 1 + nextRow[curr + 1];
                }

                int notTake = nextRow[prev + 1];
                
                currRow[prev + 1] = max(take, notTake);
            }

            nextRow = currRow;
        }

        return nextRow[0];        
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // int ans = solve(nums, 0, -1, dp);
        // return ans < 0 ? 0 : ans;
        return spaceOptimised(nums);
    }
};