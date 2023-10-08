#include <bits/stdc++.h> 

// W -> maxWeight, N -> number of items

// Time -> O(N*W) 
// Space -> O(N*W)
int topDown(int ind, vector<int> &weight, vector<int> &value, int n, int capacity, vector<vector<int>> &dp){

  	if (ind >= n) {
		return 0;
	}

	if(dp[ind][capacity] != -1){
		return dp[ind][capacity];
	}

    int include = 0;

	if(capacity >= weight[ind]){
		include = value[ind] + topDown(ind + 1, weight, value, n, capacity - weight[ind], dp);
	}

	int exclude = topDown(ind + 1, weight, value, n, capacity, dp);

	return dp[ind][capacity] = max(include, exclude);
}

// Time -> O(N*W) 
// Space -> O(N*W)
int bottomUp(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n, vector<int> (capacity + 1, 0));

	for(int wt = weight[0]; wt <= capacity; wt++){
		dp[0][wt] = value[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int wt = 1; wt <= capacity; wt++){

			int include = 0;
			if(wt >= weight[ind]){
				include = value[ind] + dp[ind - 1][wt - weight[ind]];
			}

			int exclude = dp[ind - 1][wt];

			dp[ind][wt] = max(include, exclude);
		}
	}

	return dp[n - 1][capacity];	
}

// Time -> O(N*W) 
// Space -> 2 * O(W)
int bottomUpSO1(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<int> prev(capacity + 1, 0);
	vector<int> curr(capacity + 1, 0);

	for(int wt = weight[0]; wt <= capacity; wt++){
		prev[wt] = value[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int wt = 1; wt <= capacity; wt++){

			int include = 0;
			if(wt >= weight[ind]){
				include = value[ind] + prev[wt - weight[ind]];
			}

			int exclude = prev[wt];

			curr[wt] = max(include, exclude);
		}

		prev = curr;
	}

	return prev[capacity];	
}

// Time -> O(N*W) 
// Space -> O(W)
int bottomUpSO2(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<int> curr(capacity + 1, 0);

	for(int wt = weight[0]; wt <= capacity; wt++){
		curr[wt] = value[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int wt = capacity; wt >= 0; wt--){

			int include = 0;
			if(wt >= weight[ind]){
				include = value[ind] + curr[wt - weight[ind]];
			}

			int exclude = curr[wt];

			curr[wt] = max(include, exclude);
		}
	}

	return curr[capacity];	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
	//int ans = topDown(0, weight, value, n, maxWeight, dp);
	int ans = bottomUpSO2(weight, value, n, maxWeight);
	return ans;
}