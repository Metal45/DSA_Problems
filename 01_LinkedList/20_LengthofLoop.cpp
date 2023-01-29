// Approach find the start of loop and return its length
//O(N) TC 
// O(1) SC
Node *StartingNode(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(slow == fast){
            fast = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head == NULL){
        return 0;
    }
    
    head = StartingNode(head);
    if(head == NULL){
        return 0;
    }
    
    Node *temp = head -> next;
    int len = 1;
    while(temp != head){
        temp = temp -> next;
        len++;
    }
    return len;
}