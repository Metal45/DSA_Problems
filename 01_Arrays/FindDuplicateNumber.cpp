// Negative Marking Method
int findDuplicate(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[abs(nums[i])] < 0){
            ans = abs(nums[i]);
            break;
        }
        nums[abs(nums[i])] *= -1;
    }

    return ans;
}


// Positioning Method -> Put every element at its right index(position)
int findDuplicate(vector<int>& nums) {
    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}


// Learn Tortoise Hare method and Binary Search Mthod
