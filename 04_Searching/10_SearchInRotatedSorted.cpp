// A sorted array with distinct values has been rotated about a pivot index. Search for an element in that array.

// Brute Force : Linear Search

// Efficient Approach: Binary Search TC O(LogN) -> since the array was originally sorted and was rotated about an index pivot. So all the elements before pivot are sorted and all the elements after pivot are also sorted 
// so you can consider it as two sorted arrays which should give you a hint about using binary search. You have to find the pivot index like previous question and then compare the target
// with the pivot element and if the element is smaller than search for it in the left parrt else search for it in the right part and you can use binary search for doing it as both the 
// arrays are sorted.



int binarySearch(vector<int> arr, int x, int s, int e){
    while(s <= e){
        int mid = s + (e - s)/2;

        if(arr[mid] == x){
            return mid;
        }

        else if(arr[mid] > x){
            e = mid - 1;
        }

        else{
            s = mid + 1;
        }
    }

    return -1;
}

int pivot(vector<int> nums, int s, int e){

    while(s < e){
        int mid = s + (e - s) / 2;

        if(mid + 1 < nums.size() && nums[mid] > nums[mid + 1]){
            return mid;
        }

        if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
            return mid - 1;
        }

        if(nums[s] > nums[mid]){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return s;
}

int search(vector<int>& nums, int target) {
    int n = nums.size(), ans = -1;

    int pivotIndex = pivot(nums, 0, n - 1);
    cout << pivotIndex << endl;

    if(target >= nums[0] && target <= nums[pivotIndex]){
        ans =  binarySearch(nums, target, 0, pivotIndex);
    }else if(pivotIndex + 1 < n && target >= nums[pivotIndex + 1] && target <= nums[n - 1]){
        ans = binarySearch(nums, target, pivotIndex + 1, n - 1);
    }

    return ans;
}



// 2nd Approach -> This is also similar to the above approach only diff is instead of finding pivot before hand we check if the left half is sorted or not if not then the right half must be sorted
// and vice versa once you find out which is the sorted half you check if the element is in its range if yes you check in that part elese you check in the other part. 
// For checking if the array is sorted compare the mid with starting element


int search(vector<int>& nums, int target) {

    int s = 0;
    int e = nums.size() - 1;

    while(s <= e){
        int mid = s + (e -s)/2;
        
        if(nums[mid] == target){
            return mid;
        }

        if(nums[s] <= nums[mid]){
            if(target >= nums[s] && target <= nums[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }else{
            if(target >= nums[mid] && target <= nums[e]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
    }

    return -1;
}