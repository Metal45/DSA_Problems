Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	// approach start from head and iterate over the list for M nodes and then 
	// take another pointer traverse for n nodes delete those nodes and connect the nodes
	
	if(head == NULL){
		return head;
	}
	if(M == 0){
		return NULL;
	}
	if(N == 0){
		return head;
	}
	Node *temp = NULL;
	Node *currNode = head;

	while(currNode != NULL){
		int take = 0;
		int skip = 0;

		while(take < M && currNode != NULL){
			if(temp == NULL){
				temp = currNode;
			}else{
				temp -> next = currNode;
				temp = currNode;
			}
			currNode = currNode -> next;
			take++;
		}

		while(skip < N && currNode != NULL){
			Node *del = currNode;
			currNode = currNode -> next;
			delete del;
			skip++;
		}
	}

	if(temp != NULL){
		temp -> next = NULL;
	}
	return head;
}