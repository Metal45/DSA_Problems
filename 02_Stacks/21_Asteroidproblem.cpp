vector<int> asteroidCollision(vector<int>& arr) {
        // Approach -> TC O(N) SC O(N)
        // -> You first find out what are the conditions of collision two ast collide, it is when the first ast is to right and second one is to the left
        // -> two ast collide whenver a neg ast encounters with a pos ast. So you accordingly push and pop the ast into the stack so the ast who will remain remains in stack will never collide

        stack<int> s;
        int n = arr.size();

        for(int i = 0; i < n; i++){

            // if the stack is empty or it is a +ive ast you push it in simply
            if(s.empty() || arr[i] > 0){
                s.push(arr[i]);
            }

            // a neg ast 
            // 1. top of stack is a pos ast but greater than current neg ast -> you do nothing as neg ast explode
            // 2. top of stack is a pos ast but lesser than current neg ast -> you pop stack until you find either a smaller pos or neg or stack becomes empty and then push it
            // 3. top of stack is pos but equal to current neg ast -> you pop
            // 4. top of stack is neg -> you push it

            else{
                
                // 2 case
                while(!s.empty() && s.top() > 0 && s.top() < abs(arr[i])){
                    s.pop();
                }

                // after popping you either enounter a pos that is equal, a greater pos ast or a neg, for pos you do nothing 
                if(!s.empty() && s.top() == abs(arr[i])){ // equal, you pop
                    s.pop();
                }else if(s.empty() || s.top() < 0){ // neg, you push
                    s.push(arr[i]);
                }
            }
        }

        // now stack only contains elements that will not collide
        n = s.size();
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            int val = s.top();
            ans[i] = val;
            s.pop();
        }

        return ans;
    }