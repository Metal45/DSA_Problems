#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Approach TC O(N) SC O(1)
    // Logic : The brackets are redundant if there is no valid operation between them So push 
    // the opening bracket and operators in the stack and whenever you encounter a closing bracket pop element out until
    // you encounter opening bracket and if no operator is there between the brackets then they are redundant else not
    
    stack<char> ans;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c == '(' || c == '+' ||c == '-' ||c == '*' ||c == '/'){
            ans.push(c);
        }
        else{
            bool isRedundant = true;
            if(c == ')'){
                while(ans.top() != '('){
                    char top = ans.top();
                    if( top == '+' || top== '-' ||top == '*' ||top == '/'){
                        isRedundant = false;
                    }
                    ans.pop();
                }
                ans.pop();
                if(isRedundant == true){
                    return true;
                }
            }
        } 
    }
    return false;
}
