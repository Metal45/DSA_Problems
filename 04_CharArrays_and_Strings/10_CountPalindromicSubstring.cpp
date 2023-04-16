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


    
    // // One way to do this question TC O(N2) SC O(N) 
    // // store all the possible substrings and then check for each 
    // void substring(vector<string> &output, string s){
    //     for(int i = 0; i < s.size(); i++){
    //         string ss = "";
    //         for(int j = i; j < s.size(); j++){
    //             ss += s[j];
    //             output.push_back(ss);
    //         }
    //     }
    // }

    // void substring2(vector<string> &output, string s){
    //     for(int i = 0; i < s.size(); i++){
    //         for(int j = i, k = 1; j < s.size(); j++, k++){
    //             string ss = s.substr(i,k);
    //             output.push_back(ss);
    //         }
    //     }
    // }

    // bool isPalindrome(string S){
    //     if(S.size() == 0 || S.size() == 1){
    //         return true;
    //     }

    //     int s = 0, e = S.size() - 1;

    //     while(s <= e){
    //         if(S[s] != S[e]){
    //             return false;
    //         }
    //         s++;
    //         e--;
    //     }

    //     return true;
    // }

    // int countSubstrings(string s){
    //     vector<string> ans;
    //     substring2(ans, s);

    //     int count = 0;
    //     for(int i = 0; i < ans.size(); i++){
    //         if(isPalindrome(ans[i]) == true){
    //             count++;
    //         }
    //     }

    //     return count;
    // }
};