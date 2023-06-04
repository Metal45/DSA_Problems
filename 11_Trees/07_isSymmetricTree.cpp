// check if the tree is Symmetric 

// same as muirror trees (last question) just pass the left and right child of root as the two trees that has to be mirror 
// if the left sub tree and right subtree of root are mirror trees the three will be symmetric 

class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL || p -> val != q -> val){
            return false;
        }

        bool leftans = solve(p -> left, q -> right);
        bool rightans = solve(p -> right, q -> left);

        return leftans && rightans;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        
        return solve(root->left, root->right);
    }
};