class Solution {
public:
    int maxValue(TreeNode *root){
        while(root -> right != NULL) {
            root = root -> right;
        }

        return root -> val;
    }

    int minValue(TreeNode *root){
        while(root -> left != NULL){
            root = root -> left;
        }

        return root -> val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root -> val == key){
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }

            else if(root -> left != NULL && root -> right == NULL){
                TreeNode *temp = root -> left;
                delete root;
                return temp;
            }

            else if(root -> left == NULL && root -> right != NULL){
                TreeNode *temp = root -> right;
                delete root;
                return temp;
            }

            else{
                int min = minValue(root -> right);
                root -> val = min;
                root -> right = deleteNode(root -> right, min);
                return root;
            }
        }

        else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else{
            root -> right = deleteNode(root -> right, key);
            return root;
        }
    }
};