vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        // Approach -> TC O(N*Q) SC O(Q) vector
        // simply count the number of nge by traversing the array starting from the given index and do this query number of times
        int i = 0, count;
        vector<int> ans;
        while(queries--){
            count = 0;
            int ind = indices[i++];
            for(int j = ind; j < n; j++){
                if(arr[j] > arr[ind]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
}