int findKthPositive(vector<int>& nums, int k) {
    // Do it again 
    int s = 0, e = nums.size() - 1;
    while(s <= e){
        int mid = s + (e - s)/2;
        int count = nums[mid] - mid - 1;
        
        if(count < k){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }

    // why this ?
    return s + k;
}