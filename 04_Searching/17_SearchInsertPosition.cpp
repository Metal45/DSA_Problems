// Return Accurate Position to insert an element into a sorted array


// Brute Force TC O(N) SC O(1) -> Linear Search -> Search for the index of the element less than or equal to the target element 

// Efficient Approach TC O(LogN) SC O(1) -> Its simple binary serach you have to return the lower bound of the element you want to insert in the array


int searchInsert(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] <= target){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return ans + 1;

        // // Linear Search O(N)
        // int n = nums.size(), ans = -1;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == target){
        //         return i;
        //     }else if(nums[i] < target){
        //         ans = i;
        //     }else{
        //         break;
        //     }
        // }
        // return ans + 1;
    }