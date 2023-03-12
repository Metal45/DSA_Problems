string reverseOnlyLetters(string S) {
    int s = 0;
    int e = S.size() - 1;
    // while(s <= e){
    //     while(s <= e && (!(S[s] >= 'a' && S[s] <= 'z') && !(S[s] >= 'A' && S[s] <= 'Z'))){
    //         s++;
    //     }

    //     while(s <= e && (!(S[e] >= 'a' && S[e] <= 'z') && !(S[e] >= 'A' && S[e] <= 'Z'))){
    //         e--;
    //     }

    //     if(s <= e){
    //         swap(S[e], S[s]);
    //         s++;
    //         e--;
    //     }
    // }

    while(s <= e){
        if(isalpha(S[s]) && isalpha(S[e])){
            swap(S[s], S[e]);
            s++;
            e--;
        }

        if(!isalpha(S[s])){
            s++;
        }else if(!isalpha(S[e])){
            e--;
        }
    }
        
    return S;
}