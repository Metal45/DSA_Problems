string expandingAroundcentre(string s, int i, int j){
    int n = s.length(), count = 1;
    string ans;
    
    while(i >= 0 && j < n && s[i] == s[j]){
        ans = s.substr(i, j - i + 1);
        count++;
        i--;
        j++;
    }
    
    return ans;
}

int expandAroundCentre(string s, int i, int j){
    int count = 1;

    while(i >= 0 && j < s.length() && s[i] == s[j]){
        count++;
        i--;
        j++;
    }

    return j - i - 1;
}


string longestPalindrome(string s) {
    int maxLength = 0, S = 0;
    string ans;

    for(int i = 0; i < s.length(); i++){
        
        int odd = expandAroundCentre(s, i, i);      
        int even = expandAroundCentre(s, i, i + 1);
        
        int len = max(odd, even);

        if(len > maxLength){
            S = i - (len - 1)/ 2;
            maxLength = len;
        }
    }

    return s.substr(S, maxLength);

    // for(int i = 0; i < s.size(); i++){
    //     string odd = expandingAroundcentre(s, i, i);

    //     if(odd.length() > maxLength){
    //         maxLength = odd.length();
    //         ans = odd;
    //     }

    //     string even = expandingAroundcentre(s, i , i + 1);
    //     if(even.length() > maxLength){
    //         maxLength = even.length();
    //         ans = even;
    //     }
    // }

    // cout << maxLength << endl;
    // return ans;
}