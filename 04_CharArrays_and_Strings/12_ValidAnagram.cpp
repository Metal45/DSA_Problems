bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    if(s == t){
        return true;
    }else{
        return false;
    }
    
    // map<char, int> one;
    // for(int i = 0; i < s.size(); i++){
    //     one[s[i]]++;
    // }

    // map<char, int> two;
    // for(int i = 0; i < t.size(); i++){
    //     two[t[i]]++;
    // }

    // for(int i = 0; i < s.size(); i++){
    //     if(one[s[i]] != two[s[i]]){
    //         return false;
    //     }
    // }

    // return true;
}