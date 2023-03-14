// solve this using priority queue also

string reorganizeString(string s) {
    // counting the freq of characters
    map<char, int> freq;
    char max_freq_char;
    int max_freq = INT_MIN;

    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }

    // fiding the most frequent character
    for(auto i : freq){
        if(i.second > max_freq){
            max_freq = i.second;
            max_freq_char = i.first;
        }
    }

    if(max_freq == 1){
        return s;
    }

    int i = 0;  
    while(max_freq > 0 && i < s.size()){
        s[i] = max_freq_char;
        max_freq--;
        i += 2;
    }

    // checking if the string can be reorganised or not
    if(max_freq != 0){
        return "";
    }else{
        freq.erase(max_freq_char);
    }


    // placing the rest of the characters
    for(auto k : freq){
        int n = k.second;
        char c = k.first;

        while(n--){
            if(i >= s.size()){
                i = 1;
            }  
            s[i] = c;
            i += 2;
        }

        freq.erase(c);
    }

    return s;
}