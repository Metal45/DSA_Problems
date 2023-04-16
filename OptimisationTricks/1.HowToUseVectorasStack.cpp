bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    // How to use vector as a stack
    int k = -1, i = 0;
    for(int j = 0; j < pushed.size(); j++){

        pushed[++k] = pushed[j];
        while(k != -1 && pushed[k] == popped[i]){
            k--;
            i++;
        }

    }

    return k == -1 ? true : false;
}