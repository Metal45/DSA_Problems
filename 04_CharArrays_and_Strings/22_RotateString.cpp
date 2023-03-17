bool rotateString(string s, string goal) {
    if(s.size() != goal.size()){
        return false;
    }

    string newString = s + s;
    int pos = newString.find(goal);

    if(pos == string::npos){
        return false;
    }else{
        return true;
    }
}