 Node * removeDuplicates( Node *head) 
    {
        // 1st approach using maps
        // visiting the node and checking if the node is alredy visted by storing the data if yes skip the node else move to the next node
        // O(n) TC o(n) Space complexity
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        map<int, bool> visited;
        Node *temp = head;
        visited[temp -> data] = true;
        
        while(temp -> next != NULL){
            if(visited[temp -> next -> data] == true){
                temp -> next = temp -> next -> next;
            }else{
               visited[temp -> next -> data] = true; 
               temp = temp -> next;
            }
        }

        // 2nd approach using loops 
        // compare the current element in the list with the help of another nested loop and delete the duplicate nodes
        
        return head;
    } 