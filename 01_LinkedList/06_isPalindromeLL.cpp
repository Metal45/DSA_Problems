int length(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

bool isPalindrome(Node *head)
{
    //Write your code here
    // -> 1st approach Two pointer approach O(n2)
    // start from head and then traverse to last node and compare it and then move to second and than traverse till second last node 
    // and compare it do this until you reach the middle node

    if(head == NULL){
        return true;
    }
    
    bool b = true;
    Node *low = head;
    Node *high = head;
    int len = length(head);

    for(int i = 0; i < (len/2); i++){
        for(int j = 0; j < len - i - 1; j++){
            high = high -> next;
        }
        if (low->data != high->data) {
          b = false;
        }
        low = low->next;
        high = head;
    }

    return b;
}