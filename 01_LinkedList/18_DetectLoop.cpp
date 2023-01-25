bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode *slow = head, *fast = head;
        // -> Tortoize hare method 
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }