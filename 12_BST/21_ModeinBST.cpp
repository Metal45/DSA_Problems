class Solution {
public:
    void solve(TreeNode *root, vector<int> &ans, int &maxFreq, int &currFreq, int &prev){
        if(root == NULL){
            return;
        }

        solve(root -> left, ans, maxFreq, currFreq, prev);
        int curr = root -> val;
        
        if(curr == prev){
            currFreq++;
        }else{
            currFreq = 1;
        }

        if(currFreq == maxFreq){
            ans.push_back(curr);
        }else if(currFreq > maxFreq){
            ans = {curr};
            maxFreq = currFreq;
        }

        prev = curr;
        solve(root -> right, ans, maxFreq, currFreq, prev);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxFreq = INT_MIN, currFreq = 0, prev = INT_MIN;
        solve(root, ans, maxFreq, currFreq, prev);
        return ans;
    }
};