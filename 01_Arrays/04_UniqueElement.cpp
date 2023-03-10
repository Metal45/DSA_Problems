int singleNumber(vector<int>& nums) {


    // Optimal Approach Using XOR -> TC O(N) SC O(1)
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }
        return ans;



    // //  Better Approach Using Hasmmaps -> TC O(N) SC O(N)
        // int n = nums.size(), ans = 0;   
        // map<int, int> freq;

        // for(int i = 0; i < n; i++){
        //     freq[nums[i]]++;
        // }

        // for(auto i: freq){
        //     if(i.second == 1){
        //         ans = i.first;
        //     }
        // }
        
        // return ans;




    // // Brute Force Approach -> TC O(N2) SC O(1) 
    // int n = nums.size(), count = 0;
    // for(int i = 0; i < n; i++){
    //     int curr = nums[i];
    //     count = 0;
    //     for(int j = 0; j < n; j++){
    //         if(nums[j] == curr){
    //             count++;
    //         }
    //     }
    //     if(count == 1){
    //         count = curr;
    //         break;
    //     }
    // }

    // return count;
    }
    