#include <iostream>
#include <vector> 
using namespace std;


vector<vector<int>> ans;
int minCoins(vector<int> arr, vector<int> temp,int target){
    if(target == 0){
        ans.push_back(temp);
        return 0;
    }

    if(target < 0){
        return INT_MAX; 
    }

    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        temp.push_back(arr[i]);
        int ans = minCoins(arr, temp, target - arr[i]);
        if(ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
        temp.pop_back();
    }

    return mini;
}

// vector<vector<int>> ans;
// void minCoins(int ind, vector<int> arr, vector<int> temp, int curr, int target){
//     if(curr == target){
//         ans.push_back(temp);
//         return;
//     }

//     if(curr > target){
//         return; 
//     }

//     for(int i = ind; i < arr.size(); i++){
//             temp.push_back(arr[i]);
//             curr += arr[i];
//             minCoins(ind, arr, temp, curr, target);
//             curr -= arr[i];
//             temp.pop_back();
//     }
// }

int main(){
    vector<int> arr = {2, 3, 6, 7};
    vector<int> temp;
    int count = minCoins(arr, temp, 7);
    cout << count << " " << endl;
    for(int i = 0; i < ans.size(); i++){
        vector<int> curr = ans[i];
        for(int j = 0; j < curr.size(); j++){
            cout << curr[j] << " ";
        }
        cout << endl;
    }
}