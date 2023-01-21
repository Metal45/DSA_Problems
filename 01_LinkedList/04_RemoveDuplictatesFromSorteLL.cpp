Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL){
		return head;
    }
    
// -> 1st approach 
    Node *temp = head;
    while(temp -> next != NULL){
        if(temp -> data == temp -> next -> data){
            temp -> next = temp -> next -> next;
        }
        else{
            temp = temp -> next;
        }
    }
    
// -> two pointer approach;
// -> start two pointers from head and head -> next if t2 is greater than t1 then connect it and move forward else just move forward

//     Node *t1 = head;
//     Node *t2 = head -> next;
    
//     while(t2 != NULL){
        
//         if(t2 -> data > t1 -> data){
//         	t1 -> next = t2;
//             t1 = t2;
//         }
//         t2 = t2 -> next;
        
//         if(t2 == NULL){
//             t1 -> next = NULL;
//         }
//     }
    
    return head;
}