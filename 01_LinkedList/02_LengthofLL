i
nt findNode(Node *head, int n){
    // Write your code here.

    // -> iterative approach O(n)

    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp -> data == n){
            return count;
        }
        count++;
        temp = temp -> next;
    }
    return -1;


    
    //-> recursive approach
    // if(head == NULL){
    //     return -1;
    // }
    // if(head -> data == n){
    //     return 0;
    // }
    // int c =  findNode(head -> next, n);
    // if(c == -1){
    //     return -1;
    // }
    // return c + 1;
}