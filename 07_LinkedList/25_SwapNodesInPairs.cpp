ListNode* swapPairs(ListNode* head) {
        // first edge case of swappig nodes that is head and next node can be managed by creating a dummy node so prev is never NULL 
        //1st Approach using dummyNode so to eliminate the first case of swapping the first two nodes so prev != NULL
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *dummyNode = new ListNode(-1, head);
        ListNode *prev = dummyNode, *curr = head;

        while(curr != NULL && curr -> next != NULL){
            prev -> next  = curr -> next;
            curr -> next = prev -> next -> next;
            prev -> next -> next = curr;

            prev = curr;
            curr = curr -> next;
        }

        return dummyNode -> next;

        // // 2nd Approach
        // ListNode *prev = NULL, *curr = head, *Next = NULL;
        // while(curr != NULL){
        //     Next = curr -> next;
        //     if(prev == NULL){ //swapping the first two nodes
        //         head = Next;
        //         curr -> next = Next -> next;
        //         Next -> next = curr;
        //     }
        //     else if(Next != NULL){ // this condition is for the odd length LL as there Next == NULL at last and you accees Next -> next
        //         // swapping the rest of the nodes
        //         prev -> next = Next;
        //         curr -> next = Next -> next;
        //         Next -> next = curr;
        //     }
        //     prev = curr;
        //     curr = curr -> next;
        // }
        // return head;
    }