class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>> &ans, int i){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }    
       
        temp.push_back(nums[i]);
        solve(nums, temp, ans, i + 1);
        temp.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }

        solve(nums, temp, ans, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, temp, ans, 0);
        return ans;
    }
};