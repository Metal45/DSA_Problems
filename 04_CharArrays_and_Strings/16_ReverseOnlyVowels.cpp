bool isVowel(char c){
    if(c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u' || c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' || c == 'U'){
        return true;
    }else{
        return false;
    }
}

string reverseVowels(string S) {
    int s = 0;
    int e = S.size() - 1;

    while(s <= e){
    if(isVowel(S[s]) && isVowel(S[e])){
        swap(S[s], S[e]);
        s++;
        e--;
    }

    if(!isVowel(S[s])){
        s++;
    }else if(!isVowel(S[e])){
        e--;
    }
}
    
return S;
}