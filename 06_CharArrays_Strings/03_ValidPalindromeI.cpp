bool check(string S){
    int s = 0, e = S.size() - 1;
    while(s <= e){
        if(S[s] != S[e]){
            return false;
        }
        s++;
        e--;
    }

    return true;
}

bool isPalindrome(string s) {
    
    string ans;
    for(int i = 0; i < s.size(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans.push_back(s[i]);
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            ans.push_back(s[i] + 32);
        }
    }

    if(check(ans)){
        return true;
    }else{
        return false;
    }
}