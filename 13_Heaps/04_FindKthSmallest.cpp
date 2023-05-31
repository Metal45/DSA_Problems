// iski time complexity kya hogi O(N) ya O(NlogK) 1 
// Find Kth smallest element in an array

// using minHeap? T.C O(NLogK) S.C O(N)-> yes you can but it will require O(N) space as you will push every element and then remove k - 1 elemetns 
        // why not minHeap? > O(N) space you can do it in O(K) space
        // how to solve via maxHeap? T.C -> O(NLogK) SC -> O(K)
            // 1. for finding kth smallest element you need to remove n - k larger elements from kth smallest element 
            // 2. form a heap of size k and push elements one by one and remove the top elment every time that way you remove n - k largest element and now the top left is the kth smallest element.
            // 3. you can optimise it and only push new and remove top when it is smaller than the top else you will add a new top and remove the same which is redundant.

        // how is it working


    int findKthSmallest(vector<int>& nums, int k){ -> // O(klogK) + O(nlogk)
        priority_queue<int> q;

        // O(klogk)
        // ye step ka time kya hoga?
        // 1 + log2 + log3 + log4 + ..... + log k = log(1*2*3*4....*k)
        for(int i = 0; i < k; i++){
            q.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){ // n - k
            // log k
            if(nums[i] < q.top()){
                q.pop();
                q.push(nums[i]);
            }            
        }

        return q.top();
    }



// similarly find kth largest element in the array
// there exists an optimal way also

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < k; i++){
            q.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }

        return q.top();
    }
