#include <bits/stdc++.h>
using namespace std;

// Approach -> TC : NlogN, SC : N
//  1. Since we have to find the maxinum number of envelopes that can be russian dolled
//  2. For having two envelopes russian dolled both the height and width of the envelop containing the other envelope must be strictly greater that the envelope contained
// 3. Now we get the intuition to use LIS here but since this is a 2D vector we will sort the envelopes either on the increasing order of widhts or heights and do LIS on the other parameter
// 4. Now we have sorted the envelopes on 1 parameter (suppose width) and we know the width of prev envelope will be less than or equal to the width of current envelope
// 5. Case 1:  if prev width is less than the current width, if the current height is also greater than the prev height we can take the envelope else we can not -> (LIS on height as we know the width is already sorted)
// 7. Case 2: We can only consider taking the current envelope if the prev width is less than the current width so for the equal widths we will sort the vector in decreasing order of heights so the envelope with lesser height will come later and as a result it will never be considered -> for ex (6,7) , (6,4)
// 8. here the widths are same but height(curr) < height(prev) so it wont be considered
// 9. Now we can further optimise the LIS using Binary Search 


//Sorted on heigth LIS on width

class Solution {
public:


    int solve(vector<vector<int>> &envelopes, int i, int prev, vector<vector<int>> &dp) {
        if(i >= envelopes.size()) {
            return 0;
        }

        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int take = INT_MIN;
        if(prev == -1 || envelopes[i][1] > envelopes[prev][1]) {
            take = 1 + solve(envelopes, i + 1, i, dp);
        }

        int notTake = solve(envelopes, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int optimal(vector<vector<int>>& envelopes) {
        vector<int> ans;
        ans.push_back(envelopes[0][0]);
        for(int i = 1; i < envelopes.size(); i++) {
            if(envelopes[i][0] > ans.back()) {
                ans.push_back(envelopes[i][0]);
            }else {
                int index = lower_bound(begin(ans), end(ans), envelopes[i][0]) - begin(ans);
                ans[index] = envelopes[i][0];
            }
        }

        return ans.size();
    }


   
    static bool myCmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) {
            return a[0] > b[0];
        }

        return a[1] < b[1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // int n = envelopes.size();
        sort(begin(envelopes), end(envelopes), myCmp);
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return solve(envelopes, 0, -1, dp);
        return optimal(envelopes);
    }
};


// Sorted on width LIS on height

class Solution {
public:
    int solve(vector<vector<int>> &nums, int i, int prev, vector<vector<int>> &dp) {
        if(i >= nums.size()) {
            return 0;
        }

        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int take = INT_MIN;
        if(prev == -1 || nums[i][1] > nums[prev][1]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        int notTake = solve(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }


    int optimal(vector<vector<int>>& nums) {
        vector<int> ans;
        ans.push_back(nums[0][1]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i][1] > ans.back()) {
                ans.push_back(nums[i][1]);
            }else {
                int index = lower_bound(begin(ans), end(ans), nums[i][1]) - begin(ans);
                ans[index] = nums[i][1];
            }
        }

        return ans.size();
    }

   
    static bool myCmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // int n = envelopes.size();
        sort(begin(envelopes), end(envelopes), myCmp);
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return solve(envelopes, 0, -1, dp);
        return optimal(envelopes);
    }
};