#include <iostream>
#include <string>
using namespace std;

int lastOccurance(string s, int i, char key){
    if(i >= s.size()){
        return -1;
    }

    if(s[s.size() - 1 - i] == key){
        return s.size() - 1 - i;
    }

    return lastOccurance(s, i + 1, key);
}

int main(){
    string s = "abcdeeeeegfhduekjhfretu";
    cout << lastOccurance(s, 0, 'e');
}