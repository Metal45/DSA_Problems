// Pattern -> Recursive Call on every Element 
// smaller problem for target you see if can be formed of either of the elements of current array;

// bina index, sum, maxi ke solve krna hai
#include <iostream>
#include <vector>
using namespace std;

void maxSum(vector<int> arr, int i, int sum, int &maxi){
    if(i >= arr.size()){
        maxi = max(sum, maxi);
        return ;
    }

    maxSum(arr, i + 2, sum + arr[i], maxi);
    maxSum(arr, i + 1, sum + arr[i], maxi);
}

int main(){
    vector<int> arr = {2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    maxSum(arr, 0, 0, maxi);
    cout << maxi << endl;
}