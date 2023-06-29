// Find the Kth smallest element in the BST

// Approach -> TC O(N) SC O(N)
// Inorder traversal of BST is sorted so store the inorder traversal 
// return the k - 1 element of the traversal 

void solve(TreeNode *root, vector<int> &inorder){
    if(root == NULL){
        return;
    }

    solve(root -> left, inorder);
    inorder.push_back(root -> val);
    solve(root -> right, inorder);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;
    solve(root, inorder);

    return inorder[k - 1];
}

// Approach -> TC O(N) SC O(1)
// Inorder traversal of BST is sorted so store the inorder traversal 
// return the k - 1 element of the traversal 

class Solution {
public:
    void solve(TreeNode *root, int k, int &count, int &ans){
        if(root == NULL){
            return;
        }

        solve(root -> left, k, count, ans);
        count++;
        if(count == k) ans = root -> val;
        solve(root -> right, k, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count = 0;
        solve(root, k, count, ans);
        return ans;
    }
};


// Another Approach 
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL){
            return -1;
        }
        int leftAns = kthSmallest(root -> left, k);
        if(leftAns != -1) return leftAns;

        k--;
        if(k == 0) return root -> val;

        int rightAns = kthSmallest(root -> right, k);
        return rightAns;
    }
};