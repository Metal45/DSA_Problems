// Find the length of the diameter of a binary tree 
// Diameter of a binary tree -> legth of longest path (edges) b/w two nodes (it may not contain the root node)


// Approach -> There are 3 possibilites of diameter
// 1. diameter of the left subtree
// 2. diameter of the right subtree
// 3. or the height(left subtree) + height(right subtree)

// return the max of three


class Solution {
public:
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(height(root -> left), height(root -> right));
    }

    int solve(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int leftans = solve(root -> left);
        int rightans = solve(root -> right);
        int rootans = height(root -> left) + height(root -> right);

        return max(rootans, max(leftans, rightans));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};