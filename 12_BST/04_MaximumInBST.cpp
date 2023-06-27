// the rightmost node in the BST is the maximum node in that BST

int maxValue(Node* root) {
    // Code here
    Node *temp = root;
    if(temp == NULL) return -1;
    
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    
    return temp -> data;
}