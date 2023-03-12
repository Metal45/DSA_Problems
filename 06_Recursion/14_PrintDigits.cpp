#include <iostream>
using namespace std;

void printDigits(int n){
    if(n == 0){
        cout << endl;
        return;
    }

    printDigits(n/10);

    cout << n % 10 << " ";
}

int main(){
    printDigits(0647);
}