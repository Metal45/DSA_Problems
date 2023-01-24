Node *swapNodes(Node *head, int i, int j)
{
	// approach -> O(n) assume a general case find the pointers of the nodes to be rearranged 
	// and then take care of the edge cases while writing the code

	if(head == NULL || (i == j)){
		return head;
	}


	Node *temp = head,*prev = NULL,*p1 = NULL, *c1 = NULL, *p2 = NULL, *c2 = NULL;
	int pos = 0;
	// // finding the address of the iht and jht nodes with their previous pointers
	while(temp != NULL){
		if(pos == i){
			p1 = prev;
			c1 = temp;
		}
		if(pos == j){
			p2 = prev;
			c2 = temp;
		}
		prev = temp;
		temp = temp -> next;
		pos++;
	}

	// // swapping the nodes
	// edge cases -> if either of the node is head node then p1 or p2 will be null throwing an error while 
	// accessing their next pointer 

	if(p1 != NULL){ // if i == 0 or ith node is the head node
		p1 -> next = c2;
	}else{
		head = c2;
	}

	if(p2 != NULL){ // if j == 0 or jth node is the head node
			p2 -> next = c1;
	}else{
		head = c1;
	}
	
	// connecting the pointers
	Node *nextToc1 = c1 -> next;
	c1 -> next = c2 -> next;
	c2 -> next = nextToc1;  // wheter c2 -> next = p2 in hint or this check once again

     return head;
}