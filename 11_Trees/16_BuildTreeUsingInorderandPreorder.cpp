// you have to build tree using inorder and preorder traversal

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};



class Solution {
public:
    int searchInInorder(vector<int> &inorder, int element){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == element){
                return i;
            }
        }

        return -1;
    }

    TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd){
        if(preIndex >= preorder.size() || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[preIndex++];
        TreeNode *root = new TreeNode(element);

        int pos = searchInInorder(inorder, element);

        root -> left = solve(preorder, inorder, preIndex, inorderStart, pos - 1);
        root -> right = solve(preorder, inorder, preIndex, pos + 1, inorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;

        return solve(preorder, inorder, preIndex, inorderStart, inorderEnd);
    }
};




// we can use map to reduce the time complexity of searching the index in inorder 

map<int, int> mp;
void mapping(vector<int>& inorder){
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i; 
}

TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd){
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = inorder.size() - 1;

    mapping(inorder);

    return solve(preorder, inorder, preIndex, inorderStart, inorderEnd);
}