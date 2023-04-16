 ListNode* removeNthFromEnd(ListNode* head, int n) {
        // approach to reach the nth node from last TC O(N) SC O(1)
        // take two pointers and go to the n node from starting with fast and then move slow and fast by one until fast -> next is not null slow will point to n node from last
        ListNode *slow = head, *fast = head;
        ListNode *dummyNode = new ListNode(-1, head), *prev = dummyNode;

        while(--n){
            fast = fast -> next;
        }

        while(fast -> next != NULL){
            prev = prev -> next;
            slow = slow -> next;
            fast = fast -> next;
        }

        prev -> next = slow -> next;
        delete slow;
        return dummyNode -> next;
    }

