#include <iostream>
#include <vector>
#include <string>
using namespace std;
// check iterative method

void subsequences(string str, string output, int i){
    if(i >= str.length()){
        cout << output << endl;
        return;
    }
    
    // include
    output.push_back(str[i]);
    subsequences(str, output, i + 1);
    output.pop_back();

    // exclude
    subsequences(str, output, i + 1);
}

vector<string> ans;
void helpsub(string str, string output, int i) {

    if(i >= str.length()){
        ans.push_back(output);
        cout << output << endl;
        return;
    }
    
    // include
    output.push_back(str[i]);
    subsequences(str, output, i + 1);
    output.pop_back();

    // exclude
    subsequences(str, output, i + 1);
}


int main(){
    helpsub("abc", "", 0);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}