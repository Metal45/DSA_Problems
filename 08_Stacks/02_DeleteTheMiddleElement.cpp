void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // Recursive approach pop the elements of the stack until the size becomes half then pop the middle element 
        // and push the elements in stack again
        // TC O(N) SC O(N) 
        if(s.empty()){
            return;
        }

        if(s.size() == (sizeOfStack + 1)/2 ){
            s.pop();
            return;
        }

        int val = s.top();
        s.pop();

        deleteMid(s,sizeOfStack);

        s.push(val);
        return;


    // // approach one iterative approach take a vector and store the first half elements of the stack in stack delete the middle element of stack
    // // and the push the elements of the vectors again in stack 
    // // TC 0(N) SC O(N) extra space vector
        // vector<int> v;
        // for(int i = 0; i < sizeOfStack/2; i++){
        //     int val = s.top();
        //     v.push_back(val);
        //     s.pop();
        // }
        // s.pop();
        // for(int i = v.size() - 1; i >= 0; i--){
        //     s.push(v[i]);
        }
    }