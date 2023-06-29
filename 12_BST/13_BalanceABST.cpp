// Balance the given binary search tree 

// Approach -> O(N)
// 1. Store the inorder traversal of the given binary search tree 
// 2. Construct the BST using inorder traversal with the middle element as the root node
// 3. The formed tree will be a balanced BST

class Solution {
public:
    void findInorder(TreeNode *root, vector<int> &inorder){ // O(N)
        if(root == NULL){
            return ;
        }

        findInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right, inorder);
    }

    TreeNode *balanceBST(vector<int> &inorder, int s, int e){ // O(N)
        if(s > e){
            return NULL;
        }

        int mid = s + (e - s)/2;

        TreeNode *newNode = new TreeNode(inorder[mid]);

        newNode -> left = balanceBST(inorder, s, mid - 1);
        newNode -> right = balanceBST(inorder, mid + 1, e);

        return newNode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);

        root = balanceBST(inorder, 0, inorder.size() - 1);
        return root;
    }
};