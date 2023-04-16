// Recursion -> Include / Exclude Method or Pick Not Pick 
// Small Problem -> Pick one element and do not pick other element and call recursion for the next element 
// Do not forget to Backtrack 

void helper(vector<int> &nums, int i, vector<int> curr, vector<vector<int>> &ans){
    // base case
    if(i >= nums.size()){
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[i]); // Include Call
    helper(nums, i + 1, curr, ans);
    curr.pop_back();

    helper(nums, i + 1, curr, ans); // Exclude Call
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curr;
    vector<vector<int>> ans;
    helper(nums, 0, curr, ans);
    return ans;
}





// Backtracking -> Recursive implementation of appending method 
// you push the curr subset in ans and then append all the next elements 

void helper(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> temp){
    ans.push_back(temp);

    for(int i = index; i < nums.size(); i++){
        temp.push_back(nums[i]);
        helper(nums, i + 1, ans, temp);
        temp.pop_back();
    }

    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    helper(nums, 0, ans, temp);
    return ans;
}






// Iterative Method -> You append the next element before the previous element for making the next set of subsets

// TC -> n * 2^n
// SC -> n * 2^n

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    ans.push_back(curr); // -> empty subset

    for(int i = 0; i < nums.size(); i++){ // n
        int n = ans.size();
        for(int j = 0; j < n; j++){ // 2^n
            // appending all the elements in ans
            vector<int> temp = ans[j];
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
    }

    return ans;
}