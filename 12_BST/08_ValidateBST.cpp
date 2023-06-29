// Check if the given tree is a valid Binary Search Tree or not 

// N -> Number of nodes in a tree
// Approach -> TC O(N) 
// We have to verify the property of a BST that is the left subtree should have values less than the root node and right subtree should
// have the value greater than the root node. And left, right subtrees should also be BST.
// The range of values of root node is from LONG_MIN to LONG_MAX 
// but for left subtree it is from lower bound to the root value and for right subtree it is from root value to upper bound 
// check this recursively for left and right subtree

class Solution {
public:
    bool solve(TreeNode *root, long lb, long ub){
        if(root == NULL){
            return true;
        } 

        if(root -> val > lb && root -> val < ub){
            bool leftAns = solve(root -> left, lb, root -> val);
            bool rightAns = solve(root -> right, root -> val, ub);

            return leftAns && rightAns;
        }else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};