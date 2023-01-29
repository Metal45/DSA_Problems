    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // 1st approach TC O(N) and SC O(1)
        // Length Difference O(N) O(1)
        // maps O(n) O(n)
        // Loops O(n2) O(1)
        // One pass O(n) O(1)



        // 2nd Approach This solution is of TC O(N) and SC O(N) using maps 
        map<ListNode*, bool> visited;
        
        while(headA != NULL){
            visited[headA] = true;
            headA = headA -> next;
        }

        while(headB != NULL){
            if(visited[headB] == true){
                return headB;
            }
            headB = headB -> next;
        }

        return NULL;
    }