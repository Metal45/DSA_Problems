long long subarrayRanges(int n, vector<int> &arr) {
        // Approach -> TC O(N2) SC O(1) You start from index 1 and traverse all array and in another nested loop you
        // you traverse from i to n which will produce the subarrays and while traversing you calculate min, max
        // You can also do it in O(N3) by taversing with two loops for finding subarrays and other loop for calculating min max
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long min = arr[i], max = arr[i]; 
            for(int j = i; j < n; j++){
                if(arr[j] > max){
                    max = arr[j];
                }
                if(arr[j] < min){
                    min = arr[j];
                }
                ans = ans + max - min;
            }
        }

        return ans;
}