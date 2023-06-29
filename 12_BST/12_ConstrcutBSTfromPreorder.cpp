// You are given preorder traversal of a bst and you have to construct a BST using it


// Approach 1 -> TC(NlogN + N)
// 1. We already know how to construct a binary tree using inorder and preorder traveral
// 2. We can sort preorder to make inorder traversal as we already know the inorder traversal of A BST is sorted 
// 3. Now that we have inorder and preorder traversal we can construct the tree

class Solution {
public:
    map<int, int> mp;
    void mapping(vector<int>& inorder){
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i; 
    }

    TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd){ // n
        if(preIndex >= preorder.size() || inorderStart > inorderEnd){ 
            return NULL;
        }

        int element = preorder[preIndex++];
        TreeNode *root = new TreeNode(element);

        int pos = mp[element];

        root -> left = solve(preorder, inorder, preIndex, inorderStart, pos - 1);
        root -> right = solve(preorder, inorder, preIndex, pos + 1, inorderEnd);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end()); // n log n 
        
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;

        return solve(preorder, inorder, preIndex, inorderStart, inorderEnd);
    }
};



// Approach 2 -> 