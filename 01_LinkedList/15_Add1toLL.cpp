Node* reverse(Node *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node *curr = head, *prev = NULL, *nxt = NULL;
        while(curr != NULL){
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // Approach TC O(N)   SC O(1)
        // since adding 1 will start from the last digit we will reverse the list and add 1 to head and traverse until carry is 0 or head becomes NULL 
        if(head == NULL){
            return head;
        }
        
        head = reverse(head);
        
        Node *temp = head;
        int sum = temp -> data + 1;
        int carry = sum / 10;
        int digit = sum % 10;
        temp -> data = digit;
        while(carry != 0 || temp -> next != NULL){
            if(carry != 0){
                if(temp -> next != NULL){
                    sum = carry + temp -> next -> data;
                    digit = sum % 10;
                    carry = sum / 10;
                    temp -> next -> data = digit;
                }else{
                    sum = carry;
                    carry = sum / 10;
                    digit = sum % 10;
                    temp -> next = new Node(digit);
                }
                temp = temp -> next;
            }else{
                return reverse(head);
            }
        }
        return reverse(head);
    }