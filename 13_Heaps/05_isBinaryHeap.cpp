// check if the given binary tree is a valid binary heap
// check if the given array is a valid bianry heap


// conditions for a bianry heap 
    // 1. tree must be a complete binary tree
    // 2. every node must be greater than its children for a max heap and lesser for a min heap


class Solution {
  public:

    // what would be its time complexity
    // checking if the given tree is a complete binary tree


    bool isCompleteBT(Node* root){ // -> T.C O(N) SC O(h)
        queue<Node*> pending;
        pending.push(root);
        bool check = false;
        
        while(!pending.empty()){
            Node *top = pending.front();
            pending.pop();
            
            if(check == true && top != NULL){
                return false;
            }
            
            if(top == NULL){
                check = true;
            }
            else{
                pending.push(top -> left);
                pending.push(top -> right);
            }
        }
        
        return true;
    }


    bool isCompleteBT2(struct Node* root){ 
        queue<Node*> pending;
        pending.push(root);
        bool check = false;
        
        while(!pending.empty()){
            Node *top = pending.front();
            pending.pop();
            if(top == NULL){
                check = true;
            }
            if(check){
                while(!pending.empty()){
                    Node *curr = pending.front();
                    if(curr != NULL){
                        return false;
                    } 
                    pending.pop();
                }
            }
            if(top != NULL){
                pending.push(top -> left);
                pending.push(top -> right);
            }
        }
        
        return true;
    }
    
    // checking if the given heap follows maxHeap property 
    bool isMaxheap(struct Node *root){ // -> TC -> O(N)  SC -> O(H)
       if(root==NULL)return true;

       if(root->left)
       {
           if(root->data < root->left->data)
           return false;
       }

       if(root->right)
       {
           if(root->data<root->right->data)
           return false;
       }

       return heap(root->left) && heap(root->right);

    }
    
    
    // another way of checking if the given tree follows max heap property
    bool isMaxheap2(struct Node *tree){
        if(tree -> left == NULL && tree -> right == NULL){
            return true;
        }

        if(tree -> right == NULL){
            return tree -> data > tree -> left -> data;
        }
        
        else{
            if( (tree -> left && tree -> data > tree -> left -> data) && (tree -> right && tree -> data >  tree -> right -> data)){
              return heap2(tree -> left) && heap2(tree -> right);
            }else{
                return false;
            }
        }
    }
    
    bool isHeap(struct Node* tree) {
        // checking for both the conditions
        return isCompleteBT(tree) && isMaxheap2(tree);
    }