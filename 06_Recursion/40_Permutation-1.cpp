class Solution {
public:
    // Method - 1 -> Swapping 
    // Logic -> every number wants to be at every place so you swap every digit of the number with every digit
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        set<vector<int>> output;
        for(int i = 0; i < ans.size(); i++){
            output.insert(ans[i]);
        }
        ans.clear();
        for(auto i : output){
            ans.push_back(i);
        }
        return ans;
    }
};



// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Method - 2 -> Pick or Drop (Striver's Approach)

class Solution {
public:
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
};