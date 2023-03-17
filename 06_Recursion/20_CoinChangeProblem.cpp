// Pattern -> Recursive Call on every Element 
// smaller problem for target you see if can be formed of either of the elements of current array;


#include <iostream>
#include <vector>
using namespace std;

int minCoins(vector<int> arr, int target){
    if(target == 0){
        return 0;
    }

    if(target < 0){
        return INT_MAX;
    }

    // smaller problem;
    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        int ans = minCoins(arr, target - arr[i]);
        if(ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }

    return mini;
}

int minCoins2(vector<int> arr, int target, int output){
    if(target == output){
        return 0;
    }

    if(output > target){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        int ans = minCoins2(arr, target, output + arr[i]);
        if(ans != INT_MAX){
            mini = min(ans + 1, mini);
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {1,2,3, 5};
    int count = minCoins(arr, 7);
    int count2 = minCoins2(arr, 7, 0);
    cout << count << " " << count2 << endl;
}