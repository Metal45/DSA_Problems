Node *kReverse(Node *head, int k)
{
        if(head == NULL || k == 0){
            return head;
        }

        Node *prev = NULL, *curr = head, *nxt = NULL;
        int count = 0;

        while(count < k && curr != NULL){
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
       
        head -> next = kReverse(nxt, k);
        
        return prev;
}