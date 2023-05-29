#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main(){
    unordered_map<char, int> count;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        count[s[i]]++;
    }

    for(auto i: count){
        cout << i.first << " " << i.second << endl;
    }
}