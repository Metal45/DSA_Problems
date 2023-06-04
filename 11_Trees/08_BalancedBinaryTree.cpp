// check if a binary tree is balanced or not

// A binary tree is a balanced or height balanced binary tree if for every node the absolute diff of height of the left and right subtrees is always <= 1
// Maintains a height of Log(N)

class Solution {
public:
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(height(root -> left), height(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true; 
        }

        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        int diff = abs(leftHeight - rightHeight);

        if(diff <= 1){
            return isBalanced(root -> left) && isBalanced(root -> right);
        }else{
            return false;
        }
    }
};