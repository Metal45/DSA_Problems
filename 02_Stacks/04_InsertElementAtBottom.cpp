stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Approach store and pop the elements of the stack until it becomes empty and then push x and then push the elements back recursively
    // TC O(N) SC O(N) call stack 
    
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }

    int val = myStack.top();
    myStack.pop();

    pushAtBottom(myStack,x);

    myStack.push(val);
    return myStack;
}
