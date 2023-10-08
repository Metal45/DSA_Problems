#include <bits/stdc++.h>
#define MOD 1000000007

// Approach -> 
// 1. for every element there is n - 1 possible places so ans = (n - 1)*(subproblem solution)
// 2. now for subproblem solution that is the rest of the elements there are two possibilites ->
// 3. a) suppose you replace 0 at some i pos
//    b) the two possibilites are that i is at the intital place of 0 so now the solution of subproblem is -> f(n - 2) that is for n - 2 elements excluding 0 and i
//    c) or the 0 is at i position but i is somewhere else so the solution is -> f(n - 1) that is for n - 1 elements only excluding 0

long long int solve(int n, vector<long long int> &dp){

    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    return dp[n] = ((n - 1) % MOD * (solve(n - 1, dp) % MOD + solve(n - 2, dp) % MOD) % MOD) % MOD;
}

long long int solve2(int n){
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n ; i++){
        dp[i] = ((i - 1) % MOD * (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD) % MOD;

    }

    return dp[n];
}

long long int solve3(int n){
    if(n <= 2) return n - 1;

    long long int prev1 = 0;
    long long int prev2 = 1;

    int curr;

    for(int i = 3; i <= n; i++){
        curr = ((i - 1) % MOD * (prev1 % MOD + prev2 % MOD) % MOD) % MOD;
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}

long long int countDerangements(int n) {
    //vector<long long int> dp(n + 1, -1);
    //return solve(n , dp);
    //return solve2(n);
    return solve3(n);
}