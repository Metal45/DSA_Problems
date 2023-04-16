// Approach 
// 3 cases -> 1st no loop exist simply return
// 2nd case -> loop exists but head in not in the loop , find the prev of the srarting of loop and remove the loop
// 3rd case -> loop exists and head is in the loop so slow and fast will meet at head and you will have to handle this case other than second case 

void removeLoop(Node* head)
    {
        if(head == NULL || head -> next == NULL){
            return;
        }
        Node* slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                break;
            }
        }
        
        if(slow == fast){ // loop exists 
            slow = head;
            // imp edge case case;
            if(slow == fast){ // head is in the loop and slow and fast are on head
                while(fast -> next != slow){
                    fast = fast -> next;
                }
            }
            else{ // finding the prev node of starting node of loop and removing the loop
                while(slow -> next != fast -> next){
                    slow = slow -> next;
                    fast = fast -> next;
                }
            }
            fast -> next = NULL;
        }
    }