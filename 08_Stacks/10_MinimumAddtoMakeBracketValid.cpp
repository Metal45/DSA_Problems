    // Logic: Count the number of unbalanced brackets in the string that is the annswer as you require one bracket to balance each unbalanced bracket 

    int minAddToMakeValid(string s) {
        // //Approach 1-> TC O(N) SC O(N) using a stack
        // // Just traverse the string and push the char into the stack if you encounter and opening bracket and other wise check if top of stack is an opening bracket then pop it else push the closing bracket, size of stack will be your ans as only invalid pairs are left in stack and each reqiure a bracket to make it valid
        stack<char> ans;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '('){
                ans.push(c);
            }
            else{
                if(!ans.empty() && ans.top() == '('){
                    ans.pop();
                }else{
                    ans.push(c);
                }
            }
        }
        return ans.size();


        // // Approach 2-> TC O(N) SC O(1) Simply traverse the string and maintain the counter of open and closing brackets and for closing bracket decrease the counter of opening bracket if count of open bracket is > 0 thus you will have the count of unbalanced brackets in the string
        // int o = 0, c = 0;
        // for(int i = 0; i< s.length(); i++){
        //     char ch = s[i];
        //     if(ch == '('){
        //         o++;
        //     }else{
        //         if(ch == ')' && o > 0){
        //             o--;
        //         }else{
        //             c++;
        //         }
        //     }
        // }
        // return o + c;
    } 