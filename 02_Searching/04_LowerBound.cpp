// Find the largest element K that is either smaller than or equal to x

// Approach -> O(logN) We can find K by using binary search since we have to find an element which is just smaller than or equal to the target we will search for it 
// if we find the element return it else if it is smaller than target store it and look for it in the right part since we have to find the largest of all else search in the left part

// similarly you can also implement upper bound

int findFloor(vector<long long> v, long long n, long long x){
        
        // Binary Search O(Log n)
        int s = 0;
        int e = n - 1;
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(v[mid] == x){
                return mid;
            }
            
            if(v[mid] <= x){
                ans = mid;
                s = mid + 1; 
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
        
        
     // // linear search O(N) 
        // int ans = 0, maxAns = -1;
        // for(long long i = 0; i < n; i++){
        //     if(v[i] <= x){
        //         ans = i;
        //         maxAns = max(ans, maxAns);
        //     }else{
        //         break;
        //     }
        // }
        
        // return maxAns;
}