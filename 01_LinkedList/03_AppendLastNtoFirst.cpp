int length(Node *head){
    if(head == NULL){
        return 0;
    }
    int count = 0;
    while(head){
        head = head -> next;
        count++;
    }
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here

    // ->1st time complexity of this approach is O(N);

    if(head == NULL || n == 0){
        return head;
    }
    int len = length(head);
 
    Node *temp = head;
    
    for(int i = 0; i < len - n - 1; i++){
        temp = temp -> next;
    }

    Node *newHead = temp -> next;
    temp -> next = NULL;
    temp = newHead;
    
    while(temp -> next  != NULL){
        temp = temp -> next;
    }

    temp -> next = head;
    head = newHead;
    return head;

    

	
    // -> 2.  Two pointer approach
    // Traverse upto the point of n - 1 and then start the fast pointer and slow pointer from there positions 
    // slow will be on the new tail and fast will be on the last node of linked list and then rearrange the pointers

    // if(head == NULL || n==0){
    //     return head;
    // } 

    // Node *fast = head;
    // Node *slow = head;
    
    // for(int i  = 0; i < n; i++){
    //     fast = fast -> next;
    // }

    // while(fast -> next != NULL){
    //     fast = fast -> next;
    //     slow = slow -> next;
    // }

    // fast -> next = head;
    // head = slow -> next;
    // slow -> next = NULL;
    // return head;



    // -> 3. approach
    // While traversing the list mark the node with index = len - n - 1 as tail 
    // and find the last node of LL and then rearrange the pointers

    // if(head == NULL || n==0){
    //     return head;
    // }

    // int count = 0;
	// int len = length(head);
    
    // Node *temp = head;
    // Node *tail;
    // Node *newhead;
	
    // while(temp -> next != NULL){
    //     if (count == len - n - 1) {
    //        tail = temp;
    //        newhead = temp->next;
    //     }
    //     temp = temp -> next;
    //     count++;
    // }    
 	// temp -> next = head;
    // tail -> next = NULL;
  
	// return newhead;

    
    
    // ->4. time complexity of this approach is O(n2) 
	// -> Brute Force
    
    //     if(head == NULL){
    //         return head;
    //     }
    //     for(int i = 0; i < n; i++){
            
    //         int data = removeLast(head);
    //         head = insertStart(head, data);
    //     }   
}