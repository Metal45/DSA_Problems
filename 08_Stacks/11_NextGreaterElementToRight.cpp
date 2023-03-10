Logic -> 

Approach -> 


// 1st Variant in which you have to check the next greater element in an array circularly where output for the last element is not necessarily -1 you will have to check for every other
// element starting from the right

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--){
            int curr = nums[i % n];
            while(!st.empty() && curr >= st.top()){
                st.pop();
            }

            if(i < n){
                if(!st.empty()){
                    ans[i] = st.top();
                }
            }

            st.push(curr);
        }

        return ans;
    }





// 2nd Variant in which you dont have to cheeck circularly in the array that is answer for the last element is -1 
// Optimised Approach TC O(N) SC O(N)

    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n, -1);
        stack<long long> st;
 
        for(int i = n - 1; i >= 0; i--){
            
            long long curr = arr[i];
            
            while(!st.empty() && st.top() <= curr){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
            }
            
            st.push(curr);
        }
        
        cout << count << endl;
        return ans;
    }
        




    // // Brute Force TLE - Make an array of twice size and traverse it accordingly

   // // Brute Force- Accepted
    // // create a vector ans iterate over nums and compare it with next elements circularly and push if there exists a greater element else push -1
    // // TC O(N^2) OC O(N) using vector
    
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){   
        int num = nums[i];         
        for(int j = i + 1; j < n + i; j++){
            // checking circularly 
            int ind = j % n; 
            if(nums[ind] > num){
                ans.push_back(nums[ind]);
                break;
            }
        }
        if(ans.size() < i + 1){
            ans.push_back(-1);
        }
    }
    return ans;