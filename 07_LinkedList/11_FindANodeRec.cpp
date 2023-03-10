int findNodeRec(Node *head, int n)
{
	//Write your code here
    // Recursive approach to find a node in a LL
    
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == n)
    {
        return 0;
    }
    int c = findNodeRec(head->next, n);
    if (c == -1)
        return -1;
    return c + 1;
}