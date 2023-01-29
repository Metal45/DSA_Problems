    ListNode* rotateRight(ListNode* head, int k) {
        // TC O(N)
        // SC O(1)
        // 2 approaches 1 similar to left rorate array by d positions using reversing
        // 1st approch roate array by k is append last k to first remember to do k = k % len else you will get TLE
        if(head == NULL || k == 0){
            return head;
        }

        ListNode *dummyNode = new ListNode(-1, head), *temp = head;
        
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
         
        k = k % len;
        while(k> 0){
            if(temp == NULL){
                temp = head;
            }
            temp = temp -> next;
            k--;
        }

        if(temp == NULL){
            return dummyNode -> next;
        }

        while(temp -> next != NULL){
            head = head -> next;
            temp = temp -> next;
        }

        temp -> next = dummyNode -> next;
        dummyNode -> next = head -> next;
        head -> next = NULL;
        return dummyNode -> next;
        }