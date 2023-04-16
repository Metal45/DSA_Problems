// Method 1 -> 
// Pick AND Drop Type Question

class Solution {
public:
    void helper(vector<int> &candidates, vector<int> curr, vector<vector<int>> &ans, int target, int ind){
        // base case
        if(ind >= candidates.size()){
            // including in final ans
            if(target ==  0){
                ans.push_back(curr);
            }
            return;
        }

        // picking elements if they can be picked
        if(candidates[ind] <= target){
            curr.push_back(candidates[ind]);
            helper(candidates, curr, ans, target - candidates[ind], ind);
            curr.pop_back();
        }

        // moving forward to next index
        helper(candidates, curr, ans, target, ind + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int currSum = 0;
        helper(candidates, curr, ans, target, 0);
        return ans;
    }
};




// Method 2 -> 
void solve(vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int ind, int target){
    // including in final ans
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    // Looping over all variables becuase we have to include them 
    for(int i = ind; i < candidates.size(); i++){
        // include if the number is less than the tagret
        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(candidates, temp, ans, i, target - candidates[i]);
            // backtracking step
            temp.pop_back();
        }
    } 
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, temp, ans, 0, target);
    return ans;
}
};
