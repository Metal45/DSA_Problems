
bool hasCycle(ListNode *head) {

        // 1st approach 
        // Floyd cycle detection algo
        // with every iteration the distanc between the fast and slow pointer is getting decreased by 1 
        // so if there will be a loop they will meet at some point
        if(head == NULL){
            return false;
        }
        ListNode *slow = head, *fast = head;
        // -> Tortoize hare method 
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        return false;


         // 2nd approach
         // using maps
        // if(head == NULL){
        //     return false;
        // }
        // map<ListNode*, bool> visited;
        // ListNode *temp = head;
        // while(temp != NULL){
        //     if(visited[temp] == true){
        //         return true;
        //     }
        //     visited[temp] = true;
        //     temp = temp -> next;
        // }
        // return false;
 }