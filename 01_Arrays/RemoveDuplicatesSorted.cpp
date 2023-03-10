
int removeDuplicates(vector<int>& nums) {

    // Approach -> TC O(N) SC O(1) || Simply take a counter with 0 index and traverse array and just keep on 
    // putting at count index while you encounter a unique element
    int count = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[count] != nums[i]){
            nums[count + 1] = nums[i];
            count++;
        }
    }

    return count + 1;

    // // Approach -> TC O(N) SC O(N) Using HashMaps
    // map<int, int> freq;
    // int n = nums.size();
    // for(int i = 0; i < n; i++){
    //     freq[nums[i]]++;
    // }
    
    // int j = 0;
    // for(auto i : freq){
    //     nums[j++] = i.first; 
    // }
    // return freq.size();
}