// Fint the smallest divisor such that when array is divided by the divisor the sum of ceil values is less than or equal to threshold 

// Approach -> TC O(NLogN) SC O(1) : This question is very similar to last the quesition Koko eating bananas 
// Catch -> Since the minimum value of threshold is length of array so the maximum divisor is the maximum element of the array such that sum is equal to the length of array 
// The search space of this question is 1 to MaxElement of array 


int sum(vector<int> nums, int mid){
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % mid == 0){
            sum += nums[i]/mid;
        }else{
            sum += nums[i]/mid + 1;
        }
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int s = 1, e = *max_element(nums.begin(), nums.end()), ans = 0;
    
    while(s <= e){
        int mid = s + (e -s)/2;
        if(sum(nums, mid) <= threshold){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    
    return ans;
}