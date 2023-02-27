// Find how many times a sorted array has been rotated

// Efficient Approach TC O(LogN) SC O(1) -> Pivot Index is same as the number of times a array has been rotated , the only change is you come out of loop in two cases. Either a single element or
// the array has been rotated n - 1 times that is the it has become the origingal array for which the ans is the first element 

int findKRotation(int nums[], int n) {
    // Approach -> TC O(LogN) SC O(1)
    int s = 0;
    int ans = 0;
    int e = n - 1;
    while(s < e){
        int mid = s + (e - s) / 2;

        if(mid + 1 < n && nums[mid] > nums[mid + 1]){
            return mid + 1;
        }

        if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
            return mid;
        }

        if(nums[s] > nums[mid]){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return ans;
    
    
    // Brute Force Approach -> TC O(N) SC O(1)
    // int ans = 0;
    // for(int i = 0; i < n - 1; i++){
    //     if(arr[i + 1] < arr[i]){
    //         ans = i + 1;
    //         break;
    //     }
    // }
    // return ans;
}
