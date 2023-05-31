class Solution {
public:
    // O(kLogN)
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        // O(Nlog(N))
        for(int i = 0; i < piles.size(); i++){
            maxHeap.push(piles[i]);
        }

        while(k--){ // O(k)
            int maxStones = maxHeap.top();
            maxHeap.pop();
            maxStones -= maxStones/2;
            if(maxStones > 0){
                maxHeap.push(maxStones); // O(logN)
            }
        }

        int ans = 0;

        while(!maxHeap.empty()){ // O(N)
            int temp = maxHeap.top();
            ans += temp;
            maxHeap.pop();
        }

        return ans;
    }
};