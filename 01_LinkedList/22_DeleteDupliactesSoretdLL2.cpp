// do not include the dupliacte nodes
ListNode* deleteDuplicates(ListNode* head) {
        // 1st approach with 0(n) tc and O(1) sc
        // aa kyu nhi rha hai ye bhai kya ans hai iska this is a doubt
        ListNode *dummyHead = new ListNode(0, head);      
        ListNode *prev = dummyHead;

        while(head != NULL){
            if(head -> next != NULL && head -> val == head -> next -> val){
                while(head -> next != NULL && head -> val != head -> next -> val){
                    head = head -> next;
                }
                prev -> next = head -> next;
            }else{
                prev = prev -> next;
            }
            head = head -> next;
        }

        return dummyHead -> next;



        // -> 2nd approach not very good approach uses O(n) space complexity
        // -> time complexiy is O(n) but execution is slow
    //     if(head == NULL || head -> next == NULL){
    //         return head;
    //     }
    //     map<int, int> freq;
    //     ListNode *temp = head;

    //     while(temp != NULL){
    //         freq[temp -> val]++;
    //         temp = temp -> next;
    //     }

    //     temp = new ListNode(-1);
    //     head = temp;

    //     for(auto i: freq){
    //         if(i.second == 1){
    //             temp -> next = new ListNode(i.first);
    //             temp = temp -> next;
    //         }
    //     }
    //     temp -> next = NULL;
    //     return head -> next;
    }