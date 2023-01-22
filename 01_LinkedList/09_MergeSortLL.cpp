Node *mergeTwoSortedLL(Node *head1, Node *head2) {
  
  Node *newHead = new Node(-1);
  Node *p3 = newHead;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      p3->next = head1;
      head1 = head1->next;
    } else {
      p3->next = head2;
      head2 = head2->next;
    }
    p3 = p3->next;
  }

  while (head1 != NULL) {
    p3->next = head1;
    head1 = head1->next;
    p3 = p3->next;
  }

  while (head2 != NULL) {
    p3->next = head2;
    head2 = head2->next;
    p3 = p3->next;
  }

  return newHead->next;
}

Node *midNode(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node *mergeSort(Node *head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *mid = midNode(head);
    Node *h1 = head;
    Node *h2 = mid -> next;
    mid->next = NULL;
    
    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    
    return mergeTwoSortedLL(h1, h2);
}
