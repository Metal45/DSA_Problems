#include <bits/stdc++.h>
using namespace std;


class Solution {
public: 
    // memoization
    // O(Amount) as u are calculating ans for every amount once
    // space -> Stack space O(n), dpsize o(n)
    int minCoinsMemoization(vector<int> &arr, int target, vector<int> &dp){
        if(target == 0){
            return 0;
        }

        if(target < 0){
            return INT_MAX;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int mini = INT_MAX;

        for(int i = 0; i < arr.size(); i++){
            int ans = minCoinsMemoization(arr, target - arr[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }

        dp[target] = mini;
        return dp[target];
    }


    // Tabular Approach ->
    // O(Amount) as u are calculating ans for every amount once
    // space -> Stack space O(n), dpsize o(n)

    // In memoization we reduced amount/ target to 0
    // that means we went from n -> 0 top to down
    // now in tabular method we will go from bottom to up from 0 to n/ amount 

    // here dp vector represents min coins to make each index(amount) and since the size will be from 0 -> n it will be of the size target amount
    // dp[i] = j represents -> u need minimum j coins for making i rs
    // for which we know the starting point that we need 0 coins to make 0 rs
    // now we will calculate minimum coins needed for making every target from 1 to amount 
        // we will pick every coin for each target value and then calculate the min number of couns to make target using jth coin
        // number of coins for making current using using coin[j] will be 1 + dp[target - coins[j]];
        // for example for making 3 using a coin of 2 -> 1 + ans(3 - 2) -> 1 ko banane me kitne coin lage aur ek 2 ka sikka -> ans(1) + 1(2rs coin)
        // for example for making 9 using a coin of 5 -> 1 + ans(9 - 5) -> 4 ko banane me kitne coin lage aur ek 5 ka sikka -> ans(4) + 1(5rs coin)
        // for example for making 7 using a coin of 2 -> 1 + ans(7 - 2) -> 5 ko banane me kitne coin lage aur ek 2 ka sikka -> ans(5) + 1(2rs coin)
    
    // now after filling the dp array dp[target] represent the min coins requried for making target amount using minimum coins


    int minCoinsTabular(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int target = 1; target <= amount; target++){
            for(int j = 0; j < coins.size(); j++){
                if(target - coins[j] >= 0 && dp[target - coins[j]] != INT_MAX){
                    dp[target] = min(dp[target], 1 + dp[target - coins[j]]);
                }
            }
        }

        return dp[amount];
    }
    

    int coinChange(vector<int>& coins, int target) {
        // vector<int> dp(target + 1, -1);
        int ans = minCoinsTabular(coins, target);
        if(ans != INT_MAX){
            return ans;
        }else{
            return -1;
        }
    }

    // No further space optimisation possible
};