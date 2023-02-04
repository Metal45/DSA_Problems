char* reverse(char *S, int len)
{
    // Approach push the character of the string in the stack which will be stored in reversre 
    // order and the pop it one by one and store it in the string 
    // TC O(N) SC O(N) stack
    stack<int> ans;
    int i = 0;
    for(; i < len; i++){
        char ch = S[i];
        ans.push(ch);
    }
    i = 0;
    while(!ans.empty()){
        char ch = ans.top();
        S[i++] = ch;
        ans.pop();
    }
    return S;
}