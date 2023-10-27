#include <bits/stdc++.h>
using namespace std;

// Brute force with extra space -> TC : O(NlogN)
class Solution {
public:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    void inorder(TreeNode *root, vector<int> &temp) {
        if(!root) {
            return ;
        }

        inorder(root -> left, temp);
        temp.push_back(root -> val);
        inorder(root -> right, temp);
    }

    void solve(TreeNode *root, vector<int> &inorder, int &i) {
        if(!root) {
            return;
        }

        solve(root -> left, inorder, i);
        
        if(root -> val != inorder[i]) {
           
            if(first == NULL) {
                first = root;
            }else if(second == NULL) {
                second = root;
              
            }
        }
        i++;

        solve(root -> right, inorder, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        sort(begin(temp), end(temp));
        
        int i=0;
        solve(root, temp, i);
        if(first && second)
        swap(first -> val, second -> val);if(first && second)
        cout<<"a";
    }
};


// Without extra space -> TC: O(N)