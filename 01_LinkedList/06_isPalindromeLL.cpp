    int length(Node *head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head -> next;
        }
        return count;
    }

    ListNode *reverseList(ListNode *head){
        ListNode *prev = NULL, *curr = head, *Next = NULL;
        while(curr !=  NULL){
            Next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode *mid(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        // 1st approach where you reverse the second half linked list and then compare it with the first half
        // O(N) TC O(1) SC inplace
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *midN = mid(head);
        midN -> next = reverseList(midN -> next);
        ListNode *temp = head;
        midN = midN -> next;
        
        while(midN != NULL){
            if(temp -> val == midN -> val){
                temp = temp -> next;
                midN = midN -> next;
            }else{
                return false;
            }
        }
        
        // return true;

        // //2nd approach use an extra O(N) space of array to copy element in array and then compare the elements of start and end
        // //TC O(N) SC O(N)
        // vector<int> arr;
        // while(head != NULL){
        //     arr.push_back(head -> val);
        //     head = head -> next;
        // }

        // int s = 0;
        // int e = arr.size() - 1;

        // while(s <= e){
        //     if(arr[s] == arr[e]){
        //         s++;
        //         e--;
        //     }else{
        //         return false;
        //     }
        // }

        // return true;


        // // -> 3rd approach Two pointer approach Tc O(n2) Sc O(1)
        // // start from head and then traverse to last node and compare it and then move to second and than traverse till second last node 
        // // and compare it do this until you reach the middle node

        // if(head == NULL){
        //     return true;
        // }
        
        // bool b = true;
        // Node *low = head;
        // Node *high = head;
        // int len = length(head);

        // for(int i = 0; i < (len/2); i++){
        //     for(int j = 0; j < len - i - 1; j++){
        //         high = high -> next;
        //     }
        //     if (low->data != high->data) {
        //     b = false;
        //     }
        //     low = low->next;
        //     high = head;
        // }

        // return b;
    }