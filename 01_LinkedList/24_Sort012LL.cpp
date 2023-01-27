    Node* segregate(Node *head) {

        // 1st approach brute Force you count the number of 0, 1 and 2 and create a new linked list with 0, 1 and 2
        // time complexity of this approach is O(n) but the space wasted and this is not in place new space is required

        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        // int count0 = 0, count1 = 0, count2 = 0;
        
        // Node *temp = head;
        // while(temp != NULL){
        //     if(temp -> data == 0){
        //         count0++;
        //     }else if(temp -> data == 1){
        //         count1++;
        //     }else{
        //         count2++;
        //     }
        //     temp = temp -> next;
        // }
        
        // int i = 0;
        // temp = new Node(-1);
        // head = temp;
        // while(i < count0){
        //     temp -> next = new Node(0);
        //     temp = temp -> next;
        //     i++;
        // }
        // i = 0;
        // while(i < count1){
        //     temp -> next = new Node(1);
        //     temp = temp -> next;
        //     i++;
        // }
        // i = 0;
        // while(i < count2){
        //     temp -> next = new Node(2);
        //     temp = temp -> next;
        //     i++;   
        // }
        // temp -> next = NULL;
        // return head -> next;
        
        
        // 2nd approach you create 3 dummy nodesfor 0, 1, 2 and you traverse the LL and you connect the nodes with dummy heads
        // and do the pointer manipulation 
        // 0(n) Tc O(1) in place sorting
        Node *head0 = new Node(-1);
        Node *head1 = new Node(-1);
        Node *head2 = new Node(-1);
        Node *tail0 = head0, *tail1 = head1, *tail2 = head2;
    
        while(head != NULL){
            if(head -> data == 0){
                tail0 -> next = head;
                tail0 = tail0 -> next;
            }else if(head -> data == 1){
                tail1 -> next = head;
                tail1 = tail1 -> next;
            }else{
                tail2 -> next = head;
                tail2 = tail2 -> next;
            }
            head = head -> next;
        }
        
        tail0 -> next = head1 -> next;
        
        if(head1 -> next != NULL){
            tail1 -> next = head2 -> next;
        }
        else{
            tail0 -> next = head2 -> next; 
        }
       
        tail2 -> next = NULL;
        return head0 -> next;
    }