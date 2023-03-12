#include <iostream>
#include <string>
using namespace std;

void replace(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            s[i] = '@';
        }
    }
}

int main(){
    string s;
    getline(cin, s);
    cout << "input string: " << s << endl;
    replace(s);
    cout << "ouput string " << s << endl;
}