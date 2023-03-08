
// We have to return the minimum eating speed of banana per hour so that the monkey can eat banana slowly and can finish before the garderner returns that is he can eat banana in h hours or before

// Brute Force -> TC O(N2) SC O(1) The search space for this question is from 1 to maximum number of bananas in 1 pile. A monkey can eat from one pile at a time so the maximum banana in
// pile is the maximum number he can eat at a time and minimum is atleast 1 banana. So you start from 1 and go uptil N and calculate the time taken at that eating speed.

// Efficent Approach -> Binary Search O(N * Log N) Instead of searching linearly in the search space we will use binary search. If the time taken at 'mid' speed is less than or equal to h
// we will check at a even low speed as we want to eat it slowly but before the gardener arrives that is <= h and if time taken is > h then we increase out our speed and look for larger
// eating speed in right half

long long TimeTaken(vector<int> piles, int k){
        long long ans = 0; 
        for(int i = 0; i < piles.size(); i++){
            // doubt in these conditions
            // if(k < piles[i]){
            //     ans = ans + (piles[i]/k) + 1;
            // }else{
            //     ans += 1;
            //}
            if(piles[i] % k == 0){
                ans += piles[i]/k;
            }else{
                ans += (piles[i]/k) + 1;
            } 
            //ans+=(piles[i]/k)+(piles[i]%k==0 ? 0 : 1);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int s = 1, e = *max_element(piles.begin(), piles.end());
       long long k = 0;

       while(s <= e){
            int mid = s + (e - s)/2;4
            // if he wants to eat slowly and before gardener returns then he must take h time only
            // if(TimeTaken(piles, mid) == h){
            //     return mid;
            // }
            if(TimeTaken(piles, mid) <= h){
                k = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
       }
       return k; 
    }