string longestCommonPrefix(vector<string>& strs) {
    string curr = strs[0];
    int j = 0;
    bool flag = true;
    for(int k = 0; k < curr.size(); k++){
        for(int i = 1; i < strs.size(); i++){
            string temp = strs[i];
            if(j < temp.size() && (temp[j] == curr[j])){
                continue;
            }else{
                flag = false;
                break;
            }
        }

        if(flag == false){
            break;
        }else{
            j++;
        }
    }

    return curr.substr(0, j);
}