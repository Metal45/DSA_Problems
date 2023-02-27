// Think more on it -> unique will always be on the even index 

// In the given Sorted Array every element appears exactly twice and one element appears once find the single non duplicate element
// This is an index observation questiona and Observation is very important in solving this question by binary search or even any other method, when you will observe enough will all possible test cases you will conclude the following cases -> 


//Approach -> TC O(LogN) SC O(1)
// 1. if the mid is odd and pairing is on the right the unique element will be on the left
// 2. if the mid is odd and pairing is on the left the unique element will be on the right 
// 3. if the mid is even and pairing is on the right the unique element will be on the right 
// 4. if the mid is even and pairing is ont the left the unique element will be on the left

// lets see how is it working->
// The indexing will start from 0 (even) and next element will be on the odd index so until the unique element appears pairing will be like even odd, even odd. Once the unique element appears it will be odd even, odd even.

// These type of questions in binary search are index observation questions.

// Case 1 -> mid is odd 
// so now if the mid is odd and pairing is on its right that is even the unique element is has appeared before that is in the left side of the array and if pairing is on the left so the order is same and it is yet to appear so it is on the right side of array

// Case 2 -> mid is even
// so now if the mid is even and pairing is on right the element must be in the right part of the array and if the pairing is on the left side the element must be in the left part of the array

// note : unique element must be on even index

// searching and changing index must be done very carefully for that check comments in the code


int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int mid = s + (e - s)/2;

            if(mid % 2 == 0){
                if(nums[mid] == nums[mid + 1]){
                    // it can not be ans
                    s = mid + 2;
                }else{
                    // it can be the ans
                    e = mid;
                }
            }else{
                if(nums[mid] == nums[mid + 1]){
                    // it can not be ans
                    e = mid - 1;
                }else{
                    // it can not be ans
                    s = mid + 1;
                }
            }
        }

        return nums[s];
    }