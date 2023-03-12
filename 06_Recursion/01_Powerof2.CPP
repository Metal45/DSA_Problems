#include <iostream>
using namespace std;

int power(int n){
    if(n == 0){
        return 1;
    }

    return 2 * power(n -1);
}

int main(){
    
    int ans = power(10);
    cout << ans << endl;
}