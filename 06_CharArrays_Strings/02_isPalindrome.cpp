

int isPalindrome(string S)
{
    // Your code goes here
    int s = 0;
    int e = S.length() - 1;
    while(s <= e){
        if(S[s++] != S[e--]){
            return 0;
        }
    }
    return 1;
}