#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Approach -> TC: O(LogN) SC: o(1) 
        // It can be breaken into two parts -> 
        // 1. determine the number between which the msising number lies 
        // 2. determine the number using the end points


        // a. )For determining the missing number you need to find the two ends between which the number will lie
        // you can find those two numbers using binary search as if the numbers missed till the current index is less than K u need 
        // go to the right side else if the number missed till the current index is more than K you need to go to the left side 
        // by doing so u will end up with two indices high and low, where the number missed till high < k and numbers missed till low > k

        // b.) now comes part be how to determine the required number using high and low 
        // the required number is (arr[high] + left_Missing_Numbers)
        // return arr[high] + left_Missing_Numbers
        // left_Missing_Numbers = k - missed_numbers_before_high
        // missed_numbers_before_high = arr[high] - high - 1;
        // more = k - arr[high] + high + 1;
        // retun arr[high] + k - arr[high] + high + 1;
        // return high + k + 1 or low + k;   {high + 1 = low}

        int s = 0, e = arr.size() - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            int missing = arr[mid] - mid - 1;

            if(missing < k){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return s + k;
    }
};