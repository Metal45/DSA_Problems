// check if the given tree is a sum tree


// A binary tree whose node's value is equal to the sum of left subtree's value and right subtree's value, leaf nodes are considered to be sum trees
 
// Approach -> i) find the left subtree sum for root 
//             ii) find the right subtree sum for root
//             iii) check if it is true for root
//             iv) recursively check for its children

class Solution
{
    public:
    int sum(Node *root){
        if(root == NULL){
            return 0;
        }
        
        return root -> data + sum(root -> left) + sum(root -> right);
    }
    
    bool isSumTree(Node* root)
    {
        if(root == NULL){
            return true;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return true;
        }
        
        int leftData = sum(root -> left);
        int rightData = sum(root -> right);
        
        
        bool ans;
        if(root -> data == leftData + rightData){
            ans = true;
        }else{
            ans = false;
        }
        
        return ans && isSumTree(root -> left) && isSumTree(root -> right);
    }
};