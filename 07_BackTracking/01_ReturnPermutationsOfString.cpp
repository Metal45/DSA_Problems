// Return all permutations of string/ array 

// Method 1 -> Pick, Not Pick

void helper(vector<int> nums, vector<int> &curr, vector<vector<int>> &ans, bool picked[]){
    if(curr.size() == nums.size()){
        ans.push_back(curr);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(picked[i] == false){
            curr.push_back(nums[i]);
            picked[i] = true;
            helper(nums, curr, ans, picked);
            picked[i] = false;
            curr.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    bool *picked = new bool[nums.size()];
    for (int i = 0; i < nums.size(); i++) picked[i] = false;
    helper(nums, curr, ans, picked);
    return ans;
}


// Merhod 2 -> Swapping 

void helper(vector<int> &nums, vector<vector<int>> &ans, int index){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++){
        swap(nums[i], nums[index]);
        helper(nums, ans, index + 1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

