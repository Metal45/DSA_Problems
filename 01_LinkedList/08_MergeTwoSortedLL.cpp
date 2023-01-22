Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
  // 1st approach iterative approach 
  // make a new dummy node and then compare the value of head1 and head2 and connect the dummy node to the smaller value;
  

  // There id a recursive approcah also 
  
  Node *newHead = new Node(-1);
  Node *p3 = newHead;

  while(head1 != NULL && head2 != NULL){
    if(head1 -> data < head2 -> data){
      p3 -> next = head1;
      head1 = head1 -> next;
    }else{
      p3 -> next = head2;
      head2 = head2 -> next;
    }
     p3 = p3 -> next;
  }

  while(head1 != NULL){
    p3 -> next = head1;
    head1 = head1 -> next;
    p3 = p3 -> next;
  }

  while (head2 != NULL) {
    p3->next = head2;
    head2 = head2->next;
    p3 = p3->next;
  }

  return newHead -> next;
}