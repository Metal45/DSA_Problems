bool isIsomorphic(string s, string t) {

    int hash[256] = {0};
    bool check[256] = {0};

    for(int i = 0; i < s.size(); i++){
        if(hash[s[i]] == 0 && check[t[i]] == 0){
            hash[s[i]] = t[i];
            check[t[i]] = true;
        }
    }
 
    for(int i = 0; i < s.size(); i++){
        if(hash[s[i]] != t[i]){
            return false;
        }
    }

    return true;


    // if(s.size() != t.size()){
    //     return false;
    // }

    // map<char, char> freq;
    // map<char, char> freq2;
    // for(int i = 0; i < s.size(); i++){
    //     freq[s[i]] = t[i];
    //     freq2[t[i]] = s[i];
    // }

    // string temp1 = "";
    // string temp2 = "";

    // for(int i = 0; i < s.size(); i++){
    //     temp1 += freq[s[i]];
    //     temp2 += freq2[t[i]];
    // }

    // if(temp1 == t && temp2 == s){
    //     return true;
    // }else{
    //     return false;
    // }
}