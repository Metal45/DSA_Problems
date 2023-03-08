int findPairs(vector<int>& nums, int k) {

    // binary search wala aur maps wala method bhi dalna hai 
    
    sort(nums.begin(), nums.end());
    set<pair<int,int>> ans;
    int i = 0, j = 1;

    while(j < nums.size()){
        int diff = nums[j] - nums[i];
        if(diff == k){
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        
        }else if(diff > k){
            i++;
        }else{
            j++;
        }

        if(i == j){
            j++;
        }
    }

    return ans.size();
}