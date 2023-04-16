class Solution {
public:
bool solve(string &s, string &t, int m, int n){
    if(m == 0){
        return true;
    }

    if(n == 0){
        return false;
    }

    if(s[m - 1] == t[n - 1]){
        return solve(s, t, m - 1, n - 1);
    }
    
    return solve(s, t, m, n - 1);
}

bool isSubsequence(string s, string t)  {
    // Recursive Code
    return solve(s, t, s.size(), t.size());

    // // TC O(N) SC O(1)
    // int i = 0, j = 0;
    // for(; j < t.size(); j++){
    //     if(i < s.size() && (s[i] == t[j])){
    //         i++;
    //     }
    // }

    // return i == s.size() ? true : false;        
}
};