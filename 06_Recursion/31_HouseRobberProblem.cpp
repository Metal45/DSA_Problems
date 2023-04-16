// TC = O(2^n)
// SC = O(n)

int helper(vector<int>& nums, int i){
    if(i >= nums.size()){
        return 0;
    }

    int rob1 = nums[i] + helper(nums, i + 2);
    int rob2 = helper(nums, i + 1);
    
    return max(rob1, rob2);
}

int rob(vector<int>& nums) {
    return helper(nums, 0);
}