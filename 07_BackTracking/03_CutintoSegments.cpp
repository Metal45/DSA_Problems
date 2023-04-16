#include <iostream>
using namespace std;

// Did not Understand

int maxSegments(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    int ans1 = (n - x, x, y, z) + 1;
    int ans2 = (n - y, x, y, z) + 1;
    int ans3 = (n - z, x, y, z) + 1;

    return max(ans1, max(ans2, ans3));
}

int main(){
    cout << maxSegments(7,5,2,2) << endl;
}