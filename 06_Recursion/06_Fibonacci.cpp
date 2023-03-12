#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0){
        cout << "0 ";
        return 0;
    }
    if(n == 1){
        cout << "1 ";
        return 1;
    }

    int ans = fibonacci(n - 1) + fibonacci(n -2);
    cout << ans << " ";
    return ans;
}

int main(){
    int n; 
    cin >> n;
    
    int ans = fibonacci(n);
}