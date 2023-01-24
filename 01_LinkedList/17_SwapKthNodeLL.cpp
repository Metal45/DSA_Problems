ListNode* swapNodes(ListNode* head, int k) {
        
        // This traversal can give the address of the Kth node from start and Kth node from last
        ListNode *slow = head;
        ListNode *fast = head;
        while(--k){
            fast = fast -> next;
        }
        ListNode *first = fast;
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        swap(first -> val, slow -> val);
        return head;
    }