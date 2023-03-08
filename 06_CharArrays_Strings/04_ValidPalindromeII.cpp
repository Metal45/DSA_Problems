// what will be the TC as while loop will only run one time O(N) or O(N2)
// Approach -> You start checking if the string is a palindrome.
// You can remove atmost one character in the string to make it palindrome.
// whenever you encounter two unequal chracters you check if you can remove either of two and make the string a palindrome.
// if the string becomes palindrome without any of that character return true else false (as you can only remove only one)
    bool checkPalindrome(string S, int s, int e){
        while(s < e){
            if(S[s] == S[e]){
                s++;
                e--;
            }else{
                return false;
            }
        }        
        return true;
    }

    bool validPalindrome(string S) {
        int s = 0;
        int e = S.length() - 1;

        while(s < e){
            if(S[s] != S[e]){
                if(checkPalindrome(S,s+1,e) || checkPalindrome(S,s,e-1)){
                    return true;
                }else{
                    return false;
                }
            }
            else{
                s++;
                e--;
            }
        }
        

        return true;
    }