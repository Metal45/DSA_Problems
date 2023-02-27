// In a given array if an element is strictly greatee than its neighbours it is called a peak. You are given an array with multiple peaks. Return Any of the peak


// Eficient Approach Binary Search-> TC O(LogN) SC O(1) This question is very similar to peak index in mountain array except there are multiple peaks so you can return any of the peak
// Edge Case -> only a single element so do not run the loop for s = e so that will return the single element as the peak 

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int s = 0;
    int e = n - 1;

    while(s < e){
        int mid = s + (e - s)/2;

        // it returns the nearest peak
        // if(mid + 1 < e && mid - 1 >= s && nums[mid]  > nums[mid + 1] && nums[mid - 1] < nums[mid]){
        //     return mid;
        // }

        if(nums[mid] < nums[mid + 1]){
            s = mid + 1;
        }else{
            // you can do mid - 1 as e also can be the peak element 
            e = mid;
        }
    } 

    return s;


    // // Brute Force -> TC O(N) SC O(1) Linear Search 
    // int n = nums.size();
    // int i = 0;
    // while(i + 1 < nums.size() && nums[i] < nums[i + 1]){
    //     i++;
    // }
    // return i;
}