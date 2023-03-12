#include <iostream>
#include <string> 
using namespace std;

int main(){
    string s1, s2;
    
    getline(cin, s1);
    getline(cin, s2);


    if(s1.compare(s2) == 0){
        cout << " Equal" << endl;
    }else{
        cout << "Not Equal" << endl;
    }
}