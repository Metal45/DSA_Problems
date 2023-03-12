

void reverseString(vector<char>& S) {

        // TC -> O(N) SC O(1)
        int s = 0, e = S.size() - 1;
        
        while(s <= e){
            swap(S[s++], S[e--]);
        }

}
