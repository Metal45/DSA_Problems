

void printIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    while(temp != NULL && count < i){
        temp = temp -> next;
        count++;
    }
    // -> if temp after traversal points to null that is i is next index to last node 
    // -> for that this if is used 
    if(temp != NULL){
    	cout<<temp -> data;        
    }
}