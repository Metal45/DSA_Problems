// The Problem arises when two similar items are swapped with start again and again which will create similar results again and again so
// to prevent that fromm  happening we have to create a map which will keep a track of swapped objects so as to prodduce unique permutations
class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;

        for(int i = index; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }

            visited[nums[i]] = true;
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