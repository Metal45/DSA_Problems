// Naive approach -  take two additional stacks first transfer the elements of input stack to s1 then s1 to s2 and then into the input stack which will reverse the order of elements

//-> 1st approach using extra stack space
//-> Store the top element and reverse the rest of the stack using recursion and then insert all the elements of input stack in the 
// -> extra stack then insert the top elemtent in the input stack and insert the elements of extra stack back to input stack

 void reverseStack(stack<int> &input, stack<int> &extra) {

     // base case
    if(input.empty()){
        return;
    }

    // recursive call
    int val = input.top();
    input.pop();
    reverseStack(input, extra);

    // pushing all the elements of input stack in the extra stack
    while(!input.empty()){
        int temp = input.top();
        input.pop();
        extra.push(temp);
    }

    // inserting val at bottom of the input stack
    input.push(val);

    // pushing all the elements of the extra stack back into input stack
    while(!extra.empty()){
        int temp = extra.top();
        extra.pop();
        input.push(temp);
    }
 }


// // -> 2nd Approach This is the approach to reverse stack using recursion and instead of using the extra stack use recusrive funciton to insert the 
// //element at the bottom of the stack TC O(N2) SC O(N)

// void InsertAtBottom(stack<int> &input, int temp){
//     if(input.empty()){
//         input.push(temp);
//         return;
//     }
//     int temp2 = input.top();
//     input.pop();
//     InsertAtBottom(input, temp);
//     input.push(temp2);
// }

// void reverseStack(stack<int> &input, stack<int> &extra) {
//     if(input.empty()){
//         return;
//     }
//     int temp = input.top();
//     input.pop();
//     reverseStack(input,extra);
//     InsertAtBottom(input, temp);
// }



    
    
void Reverse(stack<int> &st){
    // Iterative Approach 
    // store the elements of the stack in array or 2 stacks and then push the elements back in reverse orde
    // TC O(N) SC O(N) extra space
    int *arr = new int [st.size()];
    int size = st.size();
    int i = 0;
    while(!st.empty()){
        int val = st.top();
        st.pop();
        arr[i++] = val;
    }
        
    for(int i = 0; i < size; i++){
        int val = arr[i];
        st.push(val);
    }
}