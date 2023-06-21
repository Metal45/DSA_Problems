// Return all the root -> leaf paths having the sum as target sum the approach is imilar to Path sum - I you just have to store the paths now


// Approach -> i) push the root in the temp
//            ii)check if the root is a leaf -> 
//           iii) if it is a leaf then check if sum till that node is equal to target
//                     i) if it is = target, store the temp this node and pop back
//                     ii) else pop back and simply return 
//            iv) else check in the left and right subtee 
//             v) pop back to backtrack
//            vi) base case (if(root == NULL) return false)


class Solution {
public:
    void solve(TreeNode* root, int sum, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(root == NULL){
            return;
        }

        temp.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL){
            if(sum + root -> val == target){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }

        solve(root -> left, sum + root -> val, target, ans, temp);
        solve(root -> right, sum + root -> val, target, ans, temp);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(root, 0, targetSum, ans, temp);

        return ans;
    }
};





// or passing temp without reference so no need to pop back

class Solution {
public:
    void solve(TreeNode* root, int sum, int target, vector<vector<int>> &ans, vector<int> temp){
        if(root == NULL){
            return;
        }

        temp.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL){
            if(sum + root -> val == target){
                ans.push_back(temp);
            }

            return;
        }

        solve(root -> left, sum + root -> val, target, ans, temp);
        solve(root -> right, sum + root -> val, target, ans, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(root, 0, targetSum, ans, temp);

        return ans;
    }
};