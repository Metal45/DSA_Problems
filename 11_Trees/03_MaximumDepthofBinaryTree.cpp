class Solution {
public:
    int solve(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        // height of left Subtree
        int leftHeight = solve(root -> left);

        // height of right Subtree
        int rightHeight = solve(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }

    int maxDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};