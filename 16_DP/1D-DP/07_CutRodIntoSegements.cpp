#include <bits/stdc++.h>

int solve(int n, int x, int y, int z, vector<int> &dp){
	if(n < 0){
		return INT_MIN;
	}

	if(n == 0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int ans1 = solve(n - x, x, y, z, dp) + 1;
	int ans2 = solve(n - y, x, y, z, dp) + 1;
	int ans3 = solve(n - z, x, y, z, dp) + 1;

	int result = max(ans1, max(ans2, ans3));
	return dp[n] = result;
}

int solve2(int n, int x, int y, int z){
	vector<int> dp(n + 1, INT_MIN);
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		int ans1 = INT_MIN;
		if(i - x >= 0){
			ans1 = dp[i - x] + 1;
		}

		int ans2 = INT_MIN;
		if(i - y >= 0){
			ans2 = dp[i - y] + 1;
		}
		
		int ans3 = INT_MIN;
		if(i - z >= 0){
			ans3 = dp[i - z] + 1;
		}

		dp[i] = max(ans1, max(ans2, ans3));
	}

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// vector<int> dp(n + 1, -1);
	int ans = solve2(n, x, y, z);
	return ans < 0 ? 0 : ans;
	// return solve2(n, x, y, z);
}