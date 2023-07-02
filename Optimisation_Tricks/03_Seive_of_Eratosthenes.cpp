#include <bits/stdc++.h>
using namespace std;

// According to the algorithm we will mark all the numbers which are divisible by i
// and are greater than or equal to the square of it. 

// all the element left unmarked are prime numbers

void solve(int n, vector<bool> &isPrime){
    for(int i = 2; i <= i * i; i++){
        if(!isPrime[i]){
            for(int j = i*i; j <= n; j+= i){
                isPrime[j] = true;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, false);
    isPrime[0] = false;
    isPrime[1] = false;
}