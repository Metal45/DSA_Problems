int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return length(head->next) + 1;
}

Node *bubbleSort(Node *head)
{
    int n = length(head);
    for (int i = 0; i < n; i++)
    {
        Node *prev = NULL, *curr = head, *nxt = NULL;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (curr->data > curr->next->data)
            {
                if (prev == NULL)
                {
                    nxt = curr->next;
                    head = nxt;
                    curr->next = nxt->next;
                    nxt->next = curr;
                    prev = nxt;
                }
                else
                {
                    nxt = curr->next;
                    prev->next = nxt;
                    curr->next = nxt->next;
                    nxt->next = curr;
                    prev = nxt;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}