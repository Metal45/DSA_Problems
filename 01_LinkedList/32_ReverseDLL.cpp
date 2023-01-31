Node* reverseDLL(Node * head)
{
    //Your code here
    // TC O(N) SC O(1)
    if(head == NULL){
        return head;
    }
    
    Node *curr = head, *p = NULL, *n = NULL;
    
    while(curr != NULL){
        n = curr -> next;
        curr -> next = p;
        curr -> prev = n.;
        p = curr;
        curr = n;
    }
    
    return p;
}