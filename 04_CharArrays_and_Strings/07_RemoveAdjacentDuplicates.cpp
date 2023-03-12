string removeDuplicates(string s) {
    // int i = 0;
    // while(!s.empty() && i < s.length()){
    //     if(s[i] == s[i + 1]){
    //         s.erase(i,2);
    //         i = 0;
    //     }else{
    //         i++;
    //     }
    // }
    // return s;

    // // Approach -> TC O(N) SC O(N)
    // // create a ans string and whenever there is any duplicate element the last character will be same as the duplicate one in that case you remove the character from ans string else you push back the character in the string.
    
    string ans;
    for(int i = 0; i < s.length(); i++){
        if(!ans.empty() && ans[ans.length() - 1] == s[i]){
            ans.pop_back();
        }else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}