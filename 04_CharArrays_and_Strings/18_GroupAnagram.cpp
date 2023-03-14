
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> freq;

    for(auto str : strs){
        string s = str;
        sort(s.begin(), s.end());
        freq[s].push_back(str);
    }

    for(auto i : freq){
        ans.push_back(i.second);
    }

    return ans;
}



// // 1st TLE Approach
// bool isAnagram(string s, string t) {
//     if(s.size() != t.size()) return false;

//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
    
//     if(s == t){
//         return true;
//     }else{
//         return false;
//     }
// }

// vector<vector<string>> groupAnagrams(vector<string>& strs) {

//     // TLE
//     vector<vector<string>> ans;

//     while(!strs.empty()){
//         vector<string> temp;
//         string s = strs[0];
//         temp.push_back(s);

//         int i = 1;
//         vector<string> newStrs;
//         for(;i < strs.size(); i++){
//             string t = strs[i];
//             if(isAnagram(s, t) == true){
//                 temp.push_back(t);
//             }else{
//                 newStrs.push_back(t);
//             }
//         }

//         strs = newStrs;
//         ans.push_back(temp);
//     }

//     return ans;
// }

