// Check if there exists a path from root -> leaf whose sum of nodes is equal to the target 

// Approach -> i) check if the root is a leaf -> 
//            ii) if it is a leaf then check if sum till that node is equal to target
//                     i) if it is = target return true 
//                     ii) else return false
//           iii) else check in the left and right subtee 
//            iv) return leftans || rightans
//             v) base case (if(root == NULL) return false)


class Solution {
public:
    bool solve(TreeNode* root, int sum, int target){
        if(root == NULL){
            return false;
        }

        if(root -> left == NULL && root -> right == NULL){
            if(sum + root -> val == target){
                return true;
            }else{
                // if it is a leaf no need to check for the left and right and then return false (both are null so both left and right ans will be false so directly return false)
                return false;
            }
        }

        bool left = solve(root -> left, sum + root -> val, target);
        bool right = solve(root -> right, sum + root -> val, target);

        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return solve(root, 0, targetSum);
    }
};