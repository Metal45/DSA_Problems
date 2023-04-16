#include <string.h>
bool helper(char s[], int n, int i){
	    if(i >= n/2){
            return true;
        }
    
        if(s[i] != s[n-1-i]){
            return false;
        }
    
        return helper(s, n, i + 1);
}

bool checkPalindrome(char input[]) {
    return helper(input, strlen(input), 0);
}