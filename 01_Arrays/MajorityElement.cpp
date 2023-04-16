// Boye Moore Voting Algo
int majorityElement(vector<int>& nums) {
    int count = 0;
    int num = nums[0];
    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            num = nums[i];
        }

        if(nums[i] == num){
            count++;
        }

        else{
            count--;
        }
    }

    return num;
}