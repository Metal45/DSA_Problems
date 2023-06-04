// Convert a given tree to a tree where every node contains sum of values of nodes in left and right subtrees 
    
    // Approach -> i) find the sum of left and right subtree
    //            ii) replace nodes value with sum of the left and right subtrees values
    //           iii) do this recursively for left and right child of nodes
    //            iv) replace the value of node to 0 for leaf nodes


class Solution {

  public:  
    int sum(Node *root){
        if(root == NULL){
            return 0;
        }
        
        return root -> data + sum(root -> left) + sum(root -> right);
    }
    
    void toSumTree(Node *root)
    {
        // Your code here
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            root -> data = 0;
            return ;
        }
        
        root -> data = sum(root -> left) + sum(root -> right);
        
        toSumTree(root -> left);
        toSumTree(root -> right);
    }
};