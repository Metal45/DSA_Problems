    bool isValid(string s) {
        // You traverse the string and store the characters in a stack
        // TC O(N)   SC O(N) stacks
        stack<char> ans;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                ans.push(ch);
            }else{
                if(ans.empty()){
                    return false;
                }
                char top = ans.top();
                if((ch == ')' && top == '(') || 
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(ans.empty()){
            return true;
        }
        return false;
    }