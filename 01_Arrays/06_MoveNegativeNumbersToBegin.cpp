
vector<int> separateNegativeAndPositive(vector<int> &nums){
// Dutch National Flag Algo
    int s = 0, e = nums.size() - 1;
    while(s < e){
        if(nums[s] < 0){
            s++;
        }else if(nums[e] > 0){
            e--;
        }else{
            swap(nums[s], nums[e]);
        }
    }

    return nums;
}



#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }

    return nums;



#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Dutch National Flag Algo
    int s = 0, e = nums.size() - 1;
    while(s < e){
        while(s < e && nums[s] < 0){
            s++;
        }

        while(s < e && nums[e] >= 0){
            e--;
        }

        swap(nums[s++], nums[e--]);
    }

    return nums;
}
}