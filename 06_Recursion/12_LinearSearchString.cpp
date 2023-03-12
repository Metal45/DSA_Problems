#include <iostream>
using namespace std;


int linearSearch(string s, int n, int i, char key){
    if(i >= n){
        return -1;
    }

    if(s[i] == key){
        return i;
    }

    return linearSearch(s, n, i + 1, key);
}

int linearSearch2(string s, int n, char key){
    if(n == 0){
        return -1;
    }

    if(s[0] == key){
        return n;
    }

    s.erase(0, 1);
    return linearSearch2(s, n - 1, key);
}


int main(){
    string s;
    cin >> s;

    char key;
    cin >> key;

    int ans = linearSearch(s, s.length(), 0, key);
    int ans2 = s.length() - linearSearch2(s, s.length(), key);
    
    cout << "index: " << ans <<" " << ans2 << endl;
}