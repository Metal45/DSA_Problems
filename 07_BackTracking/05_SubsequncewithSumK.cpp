
// Print all subsequences with sum K

#include <iostream>
#include <vector>
using namespace std;

// void SubsK(int i, vector<int> nums, int sum, int K, vector<int> curr){
//     if(i >= nums.size()){
//         if(sum == K){
//             for(int i : curr){
//                 cout << i << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     curr.push_back(nums[i]);
//     SubsK(i + 1, nums, sum + nums[i], K, curr);
//     curr.pop_back();

//     SubsK(i + 1, nums, sum, K, curr);
// }


// to print only one subsequence
// ->  Condition to print only one ouptut out of several outouts is you return true and false in the base case and onl make the other function call if necerssary
 
// bool SubsK(int i, vector<int> nums, int sum, int K, vector<int> curr){
//     if(i >= nums.size()){
//         if(sum == K){
//             for(int i : curr){
//                 cout << i << " ";
//             }
//             cout << endl;
//             return true;
//         }
//         return false;
//     }

//     curr.push_back(nums[i]);
//     if(SubsK(i + 1, nums, sum + nums[i], K, curr) == true){
//         return true;
//     }
//     curr.pop_back();

//     if(SubsK(i + 1, nums, sum, K, curr) == true){
//         return true;
//     };

//     return false;
// }



// count number of subsequnces

int SubsK(int i, vector<int> nums, int sum, int K, vector<int> curr){
    if(i >= nums.size()){
        if(sum == K){
            return 1;
        }

        return 0;
    }

    curr.push_back(nums[i]);
    int l = SubsK(i + 1, nums, sum + nums[i], K, curr);
    curr.pop_back();

    int r = SubsK(i + 1, nums, sum, K, curr);
    return l + r;
}


int main(){
    vector<int> nums{1,2,1};
    vector<int> curr;
    cout << SubsK(0, nums, 0, 2, curr);
}