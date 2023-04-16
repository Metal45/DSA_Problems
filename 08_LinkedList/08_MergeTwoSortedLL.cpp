Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
  // 1st approach iterative approach 
  // make a new dummy node and then compare the value of head1 and head2 and connect the dummy node to the smaller value;
 
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


// // 2nd this is the recursive approach of merging two sorted linked list 
//      if(list1 == NULL){
//             return list2;
//         }
//         if(list2 == NULL){
//             return list1;
//         }
        
//         ListNode *result;
//         if(list1 -> val < list2 -> val){
//             result = list1;
//             result -> next = mergeTwoLists(list1 -> next, list2);
//         }else{
//             result = list2;
//             result -> next = mergeTwoLists(list1, list2 -> next);
//         }
        
//         return result;
}