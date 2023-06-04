// Check if two binary trees are euqal / are the same trees

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        
        if(p == NULL || q == NULL || p -> val != q -> val){
            return false;
        }

        bool leftans = isSameTree(p -> left, q -> left);
        bool rightans = isSameTree(p -> right, q -> right);

        return leftans && rightans;
    }
};