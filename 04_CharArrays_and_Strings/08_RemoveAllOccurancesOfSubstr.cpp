string removeOccurrences(string s, string part) {
    
    // Find the next occurance of the substring using find function and erase that occurance until you do not find next pos
    // TC O(N) SC O(1)
    
    while(s.find(part) != string:: npos){
        int i = s.find(part);
        s.erase(i, part.size());
    }

    return s;
}