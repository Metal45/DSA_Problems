     
    // discuss this approach with someone how can you make it work
    // approach to solve you have to add the numbers in the linked list which is started from the last digits so you will have to reverse the linked iists 
    // but these are already reversed so no need to do that then just add the value of nodes and save the value of carry such that you can use it in the next addition
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *first = l1, *second = l2;
        ListNode *resultHead = new ListNode(-1), *resultTail = resultHead;

        int carry = 0;
        while(first != NULL || second != NULL || carry != 0){ // will execute untilt either both lists are empty or there is no carry left
            int val1 = 0;  // will give the value of node of first linked list and if empty value will be 0
            if(first != NULL){
                val1 = first -> val;
            } 
    
            int val2 = 0;  //will give the value of node of second linked list and if empty value will be 0
            if(second != NULL){
                val2 = second -> val;
            }

            int ans = carry + val1 + val2; //the sum of nodes
            int digit = ans%10; // node of resultant list
            carry = ans/10;

            resultTail -> next = new ListNode(digit);
            resultTail = resultTail -> next;

            if(first != NULL){ // moving the pointers if the lists are not empty
                first = first -> next; 
            }
            
            if(second != NULL){
                second = second -> next;
            }
        }
        return resultHead -> next;
    }   





        // int num1 = 0, num2 = 0, i = 0, ans, digit;

        // ListNode* temp = l1;
        // while(temp != NULL){
        //     digit = temp -> val;
        //     num1 = (pow(10,i) * digit) + num1;
        //     temp = temp -> next;
        //     i++;
        // }
        // temp = l2;
        // i = 0;
        // while(temp != NULL){
        //     int digit = temp -> val;
        //     num2 = (pow(10,i) * digit) + num2;
        //     temp = temp -> next;
        //     i++;
        // }

        // ans = num1 + num2;
        // if(ans == 0){
        //     ListNode *result = new ListNode(0);
        //     return result;
        // }

        // ListNode* result = new ListNode(-1);
        // temp = result;
        // while(ans != 0){
        //     digit = ans % 10;
        //     ans = ans/10;
        //     temp -> next = new ListNode(digit);
        //     temp = temp -> next;
        // }
        // return result -> next;