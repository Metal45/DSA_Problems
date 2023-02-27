// Find the peak Index in the moutian array 

// Approach -> TC O(LogN) SC O(1) 
// For finding the peak index of the array you have the under stand the following properties of the array 
// all the elements before the peak index are in a monotonic increasing order and all elements after the peak index are in a monotonic decreasing order with a peak between them
// so all the elements before and after peak are sorted which gives us hint that we can use binary search and the index we have to search for is peak index 

// imagine the array as a mountain with two lines on the left par every element is smaller than its next element so if you encounter this case you have to search in right for peak 
// and on the right part every elemet is larger than is next element if that is the case then you need to search for the peak in left part of array 

// NOTE : While you are in the right part of the array you have to also look for the element you are on as it can be the peak element which is not the case for left part as peak is larger
// the next element also. so for searching in left part include the current element.

int peakIndexInMountainArray(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int mid = s + (e - s)/2;
            
            // if(nums[mid] > nums[mid + 1] && nums[mid - 1] < nums[mid]){
            //     return mid;
            // }

            if(nums[mid] < nums[mid + 1]){
                s = mid + 1;
            }else{
                // you can not do mid - 1 becuase here mid can be the peak element 
                e = mid;
            }
        }

        return s;


        // //Brute Force TC -> O(N) SCC O(1)
        // int i = 0;
        // while(nums[i] < nums[i + 1]  && i < nums.size()){
        //     i++;
        // }

        // return i;
    }