// Find the LCA of a node in BST

// Approach -> TC O(logN) in average case and can go upto O(N) in worst case (skewed tree)
// 1. We will use the property of BST to find the LCA of the node in BST 
// 2. A LCA is A node who is the common ancestor to both which is only possible in a BST when the nodes are on different sides except if p and q are not LCA itself
// 3. if both p and q are less than the root node this means the LCA is in the left subtree 
// 4. if both p and q are greater than the root node this means the LCA is in the right subtree
// 5. else if (p < root && q > root) or (p > root && q < root) then the root node is LCA 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL){
            return NULL;
        }

        // LCA exists in right subtree
        if(p -> val > root -> val && q -> val > root -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }

        // LCA exists in the left subtree
        if(p -> val < root -> val && q -> val < root -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }

        // root is the LCA
        else{
            return root;
        }
    }
};