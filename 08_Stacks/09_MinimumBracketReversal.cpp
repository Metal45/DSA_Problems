int countRev (string s)
{
    // Approach TC O(N) SC O(N)-> push the string into the stack and pop the valid pairs, now the string contian only invalid pairs 
    // if the two brackets are same the reversing one would make them valid else you will have to reverse both, maintain a coutner
    stack<char> ans;
    
    // a odd length of string can never be made valid
    if(s.length() % 2 == 1){
        return -1;
    }
    
    // traversing the string and pushing it into stack
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c == '{'){
            ans.push(c);
        }
        else{
            if(c == '}'){
                if(!ans.empty() && ans.top() == '{'){
                    ans.pop();
                }else{
                    ans.push(c);
                }
            }
        }
    }
    
    // Now the stack only contains invalid expression 
    int count = 0;
    // Approach 1 -> 1 reversal for same brackets and 2 reversal for oppposite brackets
    while(!ans.empty()){
        char c1 = ans.top();
        ans.pop();
        char c2 = ans.top();
        ans.pop();
        
        if(c1 == c2){
            count += 1;
        }else{
            count += 2;
        }
    }
    
    return count;
    
    // // Approach 2 by obeservation the answer is (o + 1)/2 + (c + 1)/2
    // int open = 0, close = 0;
    // while(!ans.empty()){
    //     char c = ans.top();
    //     ans.pop();
    //     if(c == '{'){
    //         open++;
    //     }else{
    //         close++;
    //     }
    // }
    
    // return (open + 1)/2 + (close + 1)/2;   
}