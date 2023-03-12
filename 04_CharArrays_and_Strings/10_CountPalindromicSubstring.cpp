class Solution {
public:
// Time Complexity -> O(N2) SC O(1)
    //Approach -> expand around centre
    // here we start iterating the string and with and find the substrings
    // we do it in two parts by expanding around the centre by placing both of the pointers on the same character
    // we get all the substrings of odd length containing that character and by placing the second pointer on the next character we get all the even length substrings containing that character
    
    int expandAroundIndex(string s, int i, int j){
        // Expanding around the centre and checking if the string is palindromic
        int count = 0;
        int n = s.length();
        while(i >= 0 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            // odd length substrings 
            int odd = expandAroundIndex(s, i, i);
            count += odd;

            // even length substrings
            int even = expandAroundIndex(s, i, i+ 1);
            count += even;
        }
        return count;
    }
};