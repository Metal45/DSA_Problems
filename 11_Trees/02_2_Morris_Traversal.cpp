#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// Morris Traversal does not use any extra space and does not use recursion
// It uses the right pointer of the tree to store the inorder sucessor of the current node
// If the right pointer is NULL, then the it is pointed to the curr node to come back to it 
// after traversing the left subtree of the curr node

vector<int> MorrisinorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode *curr = root;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            // storing the left 
            inorder.push_back(curr -> val);
            curr = curr -> right; 
        } else {
            // finding the inorder predecessor of the curr node
            // rightmost node of the prev will be the inorder predecessor
            TreeNode *pre = curr -> left;
            while(pre -> right != NULL && pre -> right != curr) {
                pre = pre -> right;
            }
            
            // if the right pointer of the inorder predecessor is NULL, then we point it to the curr node
            // and go furhter left of the curr node
            if(pre -> right == NULL) {
                pre -> right = curr;
                curr = curr -> left;
            } 
            // if the right pointer of the inorder predecessor is not NULL, then we point it back to NULL
            // and traverse the right subtree of the curr node and store the curr node in the inorder vector
            else {
                pre -> right = NULL;
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }

    return inorder;
}


vector<int> MorrispreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode *curr = root;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            preorder.push_back(curr -> val);
            curr = curr -> right; 
        } else {
            TreeNode *pre = curr -> left;
            while(pre -> right != NULL && pre -> right != curr) {
                pre = pre -> right;
            }

            if(pre -> right == NULL) {
                preorder.push_back(curr -> val);
                pre -> right = curr;
                curr = curr -> left;
            } else {
                pre -> right = NULL;
                curr = curr -> right;
            }
        }
    }

    return preorder;
}