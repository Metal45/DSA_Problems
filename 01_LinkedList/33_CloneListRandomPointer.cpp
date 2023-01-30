 Node* copyRandomList(Node* head) {
    
        // 1st approach TC O(N) SC O(1)
        if(head == NULL){
            return head;
        }

        // Creating a new linked list using next pointers
        Node *temp = head, *newHead = new Node(-1), *tail = newHead;
        while(temp != NULL){
            tail -> next = new Node(temp -> val);
            tail = tail -> next;
            temp = temp -> next;
        }

        tail -> next = NULL;
        temp = head, tail = newHead -> next;
 
        // connecting the old and new linked list nodes by rearranging the links
        while(tail != NULL && temp != NULL){
            Node *tempnxt = temp -> next, *tailnxt = tail -> next;
            temp -> next = tail;
            temp = tempnxt;
            tail -> next = tempnxt;
            tail = tailnxt;
        }
        
        temp = head;

        // creating the random pointers by tracking down the random pointers from the old linked list
        while(temp != NULL){
            if(temp -> next != NULL){
                if(temp -> random != NULL){
                    temp -> next -> random = temp -> random -> next;
                }else{
                    temp -> next -> random = NULL;
                }
            }
            
            temp = temp -> next -> next;
        }

        // rearranging the next pointers to revert the changes made in step 2 after allocating the random pointers
        temp = head;
        tail = newHead -> next;
        while(temp != NULL && tail != NULL){
            temp -> next = tail -> next;
            temp = temp -> next;

            if(temp != NULL)
            tail -> next = temp -> next;

            tail = tail -> next;
        }

        return newHead -> next;




    // // 2nd Approach using maps, copy the linked list using next pointers, map the old and new nodes and then track the random of old via map and point in the new list
    // // TC 0(N), SC O(N) map
    //     if(head == NULL){
    //         return head;
    //     }
    //     map<Node*, Node*> mapping;
    //     Node *temp = head, *newHead = new Node(-1), *tail = newHead;
    //     while(temp != NULL){
    //         tail -> next = new Node(temp -> val);
    //         mapping[temp] = tail -> next;
    //         tail = tail -> next;
    //         temp = temp -> next;
    //     }
    //     tail -> next = NULL;
    //     temp = head;
    //     tail = newHead -> next;

    //     while(temp != NULL){
    //         tail -> random = mapping[temp -> random];
    //         tail = tail -> next;
    //         temp = temp -> next;
    //     }
        
    //     return newHead -> next;



    // // 3rd Approach you can also do this in TC O(N2) and SC O(1) by using two loops, traversing the list and tracking the random pointer distance from the current node and connecting the new random pointer after that distance  
    }