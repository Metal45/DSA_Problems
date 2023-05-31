// checking if the given tree is a complete binary tree
// travel level wise once you encounter a null node there should be no other non null node left in the queue than that tree is a complete binary tree


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


    // another way of checking is number each node in order , so no valid node should get a number > total nodes 
    int countNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    bool helper(Node *root, int currIndex, int count){
        
        if(root == NULL){
            return true;
        }
        
        if(currIndex > count){
            return false;
        }
        
        else{
            bool leftans = helper(root -> left, 2*currIndex, count);
            bool rightans = helper(root -> right, 2*currIndex + 1, count);
            
            return leftans && rightans;
        }
    }
    
    bool isCompleteBT(Node* root){
        //code here
        int count = countNodes(root);
        return helper(root, 1, count);
    }
    