// -> Method 1 
void solve(vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target, int i){
    // if target becomes 0 -> a valid coombination is valid
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    // if target becomes -ive -> this combination is invalid
    if(target < 0){
        return;
    }

    // picking elements from candidates
    for(int j = i; j < candidates.size(); j++){
        // skipping duplicates
        if(j > i && candidates[j] == candidates[j - 1]){
            continue;
        }

        // picking current num
        temp.push_back(candidates[j]);
        // calling for next element
        solve(candidates, temp, ans, target - candidates[j], j + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    solve(candidates, temp, ans, target, 0);
    return ans;
}


// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// -> Method 2 
void solve(vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target, int i){
    // Base Case 
    if(i >= candidates.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }

    // picking current element 
    if(candidates[i] <= target){
        temp.push_back(candidates[i]);
        solve(candidates, temp, ans, target - candidates[i], i + 1);  
        temp.pop_back();
    }

    // skipping duplicates
    while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]){
        i++;
    }
    
    // caling for next element
    solve(candidates, temp, ans, target, i + 1);
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    solve(candidates, temp, ans, target, 0);
    return ans;
}