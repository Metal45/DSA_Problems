// Find the minimum elememt in sorted rotated array 

//  Efficient Approach -> Binary Search TC O(Log N) SC O(1) Since the array was originally sorted in a non decreasing order and it was rotated about pivot the next element of pivot 
// is always the smallest element in the array except if it is a single element or it has been rotated n - 1 times.

int findMin(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = 0;

    // Edge Case -> loop will be terminated without returning anything in two cases one the array is roated n - 1 times or there is only single element in both the cases the ans will be the first element of the array
    while(s < e){
        int mid = s + (e - s) / 2;

        if(mid + 1 < nums.size() && nums[mid] > nums[mid + 1]){
            return nums[mid + 1];
        }

        if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
            return nums[mid];
        }

        if(nums[s] > nums[mid]){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    
    return nums[ans];
    
    // // Brute Force Approach -> Linear Search TC O(N) SC O(1)
    // int n = nums.size();
    // int i = 0; 
    // while(i < n - 1 && nums[i + 1] > nums[i]){
    //     i++;
    // }

    // if(i == n - 1){
    //     return nums[0];
    // }else{
    //     return nums[i + 1];
    // }
}