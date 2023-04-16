Node *reverseLinkedList(Node *head) {
    // Write your code here
    // 1st approach iterative approch of reversing the linked list in 0(n) time
    
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    while(curr != NULL){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    
    return prev;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    //1st approach recursive approach to reverse a LL 
    
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *output = reverseLinkedListRec(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return output;
}