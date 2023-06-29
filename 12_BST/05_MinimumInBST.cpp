// the leftmost node in any BST is the minimum node in that BST

int minValue(Node* root) {
    // Code here
    Node *temp = root;
    if(temp == NULL) return -1;
    
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    
    return temp -> data;
}