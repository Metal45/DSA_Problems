Node *kReverse(Node *head, int k)
{
    ListNode* reverseKGroup(ListNode* head, int k) {
    // recursive approach TC O(N), SC O(N/K) it uses the call stack for recursion
    // Approach: reverse the first k nodes and call recursion to do rest and connect the reversed nodes with the recursive output

    // base case if there are no nodes or the value of k == 1
    if(head == NULL || k == 1){
        return head;
    }

    ListNode *prev = NULL, *curr = head, *nxt = NULL, *end = head;
    int count = 0;
    
    // checking if the nodes in the group are more than k
    // it will not reverse the list if the nodes are less than k if you don't want that remove it =
    while(count < k - 1){
        end = end -> next;
        if(end == NULL){
            return head;
        }
        count++;
    }
    count = 0;

    // revrsing K nodes 
    while(curr != NULL && count < k){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    
    // recursive call to reverse rest of the list in groups of K and connecting it with the list we reversed
    head -> next = reverseKGroup(nxt, k);

    // returning the head of the new list
    return prev;
    }
}