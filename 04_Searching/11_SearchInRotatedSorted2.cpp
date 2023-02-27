// This is the follow up of previous question. Now the array contains duplicate values

bool search(vector<int>& nums, int target) {
    // what are the possible cases in which sorted in rotated array would go wrong?
    // what is the condition for duplicates?
    int s = 0;
    int e = nums.size() - 1;

    while(s <= e){
        int mid = s + (e -s)/2;
        
        if(nums[mid] == target){
            cout << mid << endl;
            return true;
        }

        if(nums[s] == nums[e] && nums[s] == nums[mid]){
            s++;
            e--;
        }
        else if(nums[s] <= nums[mid]){
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

    return false;
}