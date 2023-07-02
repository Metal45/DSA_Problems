class Solution {
public:
    void findInorder(TreeNode *root, vector<int> &inorder){
        if(root == NULL){
            return ;
        }

        findInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        findInorder(root, inorder);

        int s = 0, e = inorder.size() - 1;

        while(s < e){
            if(inorder[s] + inorder[e] == k){
                return true;
            }else if(inorder[s] + inorder[e] > k){
                e--;
            }else{
                s++;
            }
        }

        return false;
    }
}


class Solution {
public:
    bool solve(TreeNode *root, int k, map<int, bool> &present){
        if(root == NULL){
            return false;
        }

        if(present.find(k - root -> val) != present.end()){
            return true;
        }

        present[root -> val] = true;

        bool leftAns = solve(root -> left, k, present);
        bool rightAns = solve(root -> right, k, present);

        return leftAns || rightAns;
    }

    bool findTarget(TreeNode* root, int k) {
        map<int, bool> present;
        return solve(root, k, present);
    }
};