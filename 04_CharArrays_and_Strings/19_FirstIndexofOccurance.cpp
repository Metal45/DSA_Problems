int strStr(string haystack, string needle) {
    int pos = haystack.find(needle);
    if(pos == string::npos){
        return -1;
    }else{
        return pos;
    }
}


int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < m; j++){

            if(haystack[i + j] != needle[j]){
                break;
            }

            if(j == m - 1){
                return i;
            }
        }
    }

    return -1;
}