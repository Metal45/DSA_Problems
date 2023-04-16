// Similar too combination 1 and 2 just unique picks form 1 to 9 and only select the ans with k numbers in it

class Solution {
public:
    // Methpd - 1
    void solve(vector<vector<int>> &ans, vector<int> temp, int k, int target, int ind){
        if(k == 0){
            if(target == 0){
                ans.push_back(temp);
            }

            return; 
        }

        if(k < 0){
            return ;
        }

        for(int i = ind; i <= 9; i++){
            temp.push_back(i);
            solve(ans, temp, k - 1, target - i, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, k, n, 1);
        return ans;
    }
};


// Method - 2

class Solution {
public:
    void solve(int index, int sum, int n, int k, vector<vector<int>> &ans, vector<int> temp){
        if(sum <= 0){
            if(temp.size() == k){
                ans.push_back(temp);
            }
            return;
        }

        for(int i = index; i <= 9; i++){
            if(i <= sum){
                temp.push_back(i);
                solve(i + 1, sum - i, n, k, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, n, k, ans, temp);
        return ans;
    }
};


// Mehtod - 3
// Pick Drop

void solve(vector<vector<int>> &ans, vector<int> temp, int k, int target, int ind){

    if(target == 0){
        if(temp.size() == k){
            ans.push_back(temp);
        }

        return;
    }

    if(ind > 9){
        return ;
    }
    
    
    if(ind <= target){
        temp.push_back(ind);
        solve(ans, temp, k, target - ind, ind + 1);
        temp.pop_back();
    }

    solve(ans, temp, k, target, ind + 1);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, k, n, 1);
    return ans;
}
