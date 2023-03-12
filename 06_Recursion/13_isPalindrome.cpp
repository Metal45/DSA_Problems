#include <iostream>
using namespace std;

bool isPalindrome(string s, int n, int i){
    if(i >= n/2){
        return true;
    }

    if(s[i] != s[n-1-i]){
        return false;
    }

    return isPalindrome(s, n, i + 1);
}

int main(){
    string s;
    cin >> s;

    cout << isPalindrome(s, s.size(), 0);
}