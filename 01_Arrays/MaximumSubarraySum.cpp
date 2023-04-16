int maxSubArray(vector<int>& nums) {
    // Kadane's Algorithm 
    // Approach -> TC O(N) SC O(1) 
    int sum = 0;
    int maxSum = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if(sum > maxSum){
            maxSum = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return maxSum;
}