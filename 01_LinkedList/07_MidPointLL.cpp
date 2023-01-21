int length(Node *head)
{
    //Write your code here
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
   }
    return count;
}


Node *midPoint(Node *head)
{
    // Write your code here    
    // 1st 2 pointer approach
    // take a slow and fast pointer slow traverse one node at a time whereas 
    // fast traverse two nodes at a time so when fast pointer reaches the end 
    // slow will be at the middle of LL
    
    if(head == NULL || head -> next == NULL) return head;
    Node *slow = head;
    Node *fast = head -> next;
    while(fast != NULL && fast-> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow ;
    
    
    
// int len = length(head);
    // if(head == NULL || head -> next == NULL) return head;
    // Node *mid = head;
    // int count = 0;
    // while(count < (len - 1)/2){
    //     mid = mid -> next;
    //     count++;
    // }
    // return mid;
    
}