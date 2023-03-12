

int isPalindrome(string S)
{
    // Approach -> TC O(N) SC O(1)
    int s = 0;
    int e = S.length() - 1;
    while(s <= e){
        if(S[s++] != S[e--]){
            return 0;
        }
    }
    return 1;

    // Approah -> TC O(N) SC O(N)
    // reverse the string and compare it with the orignal string 
}