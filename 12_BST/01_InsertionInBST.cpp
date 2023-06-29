// Insert a node in BST

// TC -> O(logN) in Average case and can go upto O(N) in worst case
// if the val is less than root -> val go to left
// else go to right
// if root is NULL connect the node

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }

        if(val > root -> val){
            root -> right = insertIntoBST(root -> right, val);
        }else{
            root -> left = insertIntoBST(root -> left, val);
        }

        return root;
    }
};