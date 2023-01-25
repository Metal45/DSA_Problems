    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            // when slow and fast meet start another pointer from head and when new pointer 
            // and slow collide that is the starting point of the liked list
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