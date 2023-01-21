int length(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

void printReverse(Node *head)
{
//->he complexity of this approach is O(n)
//-> recursive solution

	if(head == NULL) return;
	printReverse(head -> next);
	cout<<head -> data<<" ";
	return;

    
    
// -> complexity of this approach is O(N2);
//  -> iterative solution traverse the LL for n times first till the last then second last ...upto the first node and print it 

    // int len = length(head);
    // Node *temp = head;
    // for(int i = 1; i <= len; i++){
    //     for(int j = 0; j < len - i ; j++){
    //         temp = temp -> next;
    //     }
    //     cout<<temp -> data<<" ";
    //     temp = head;
    // }
}