// TC -> O(NlogN) SC -> o(LogN)
int maxAns(vector<int> &nums, int s, int e){
    // base case (returning single element)
    if(s == e){
        return nums[s];
    }
    int mid = s + (e - s)/2;

    // max sum of the left subarray
    int leftSum = maxAns(nums, s, mid);

    // max sum of the right subarray
    int rightSum = maxAns(nums, mid + 1, e);

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

    int leftBorderSum = 0;
    // calculating the sum to left of mid(including)
    for(int i = mid; i >= s; i--){
        leftBorderSum += nums[i];
        maxLeftBorderSum = max(leftBorderSum, maxLeftBorderSum);
    }

    int rightBorderSum = 0;
    // calculating sum to the right of mid(excluding)
    for(int i = mid + 1; i <= e; i++){
        rightBorderSum += nums[i];
        maxRightBorderSum = max(rightBorderSum, maxRightBorderSum);
    }

    // crossBorderSum (sum of the whole array)
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    // max Sum of subarray can either lie on the left side or the right side or across the border
    return max(leftSum, max(rightSum, crossBorderSum));
}

int maxSubArray(vector<int>& nums) {
    int ans = maxAns(nums, 0, nums.size() - 1);
    return ans;
}