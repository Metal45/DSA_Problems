// Find the first and last occurance of an element in the given sorted array
// Follow up question -> Find tht total number of occurances of an element in the given sorted array -> lastOccurance - FirstOccurance + 1;


// Approach -> TC O(Log N) SC O(1) Make two functions for finding the first and last occurance respectively

// 1. For Finding the first occurance
// you search if the element at mid is target if yes you store it as ans and search for any further occurance in the left and update ans if you find one.

// if mid is not the target you search accordingly in the array using binary search 

// 2. For Finding the last occurance
// you search if the element at mid is target if yes you store it as ans and search for any further occurance in the right and update ans if you find one.

// if mid is not the target you search accordingly in the array using binary search 



//Approach -> TC O(logN) You can also solve this question by implementing lower bound and upper bound
    int firstOccurance(vector<int> arr, int s, int e, int x){
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(arr[mid] == x){
                ans = mid;
                e  = mid - 1;
            }

            else if(arr[mid] > x){
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }

        return ans;
    }


    int lastOccurance(vector<int> arr, int s, int e, int x){
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(arr[mid] == x){
                ans = mid;
                s  = mid + 1;
            }

            else if(arr[mid] > x){
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n  = nums.size();
        int i = firstOccurance(nums, 0, n - 1, target);
        int j = lastOccurance(nums, 0, n - 1, target);
        return {i, j};
    }