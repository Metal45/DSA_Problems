#include <iostream>
#include <vector> 
using namespace std;

// void MaxSum(vector<int> nums, int i, int sum, int &maxi){
//     if(i >= nums.size()){
//         cout << sum << " ";
//         maxi = max(sum, maxi);
//         return;
//     }

//     MaxSum(nums, i + 2, sum + nums[i], maxi);
//     MaxSum(nums, i + 1, sum, maxi);
// }

int MaxSum(vector<int> nums, int i, int sum){
    if(i >= nums.size()){
        return sum;
    }

    int ans1 = MaxSum(nums, i + 2, sum + nums[i]);
    int ans2 = MaxSum(nums, i + 1, sum);

    return max(ans1, ans2);
}

int main(){
    vector<int> nums{2, 1, 4, 9};
    int maxi = INT_MIN;
    int ans = MaxSum(nums, 0, 0);
    cout << ans << endl;
}