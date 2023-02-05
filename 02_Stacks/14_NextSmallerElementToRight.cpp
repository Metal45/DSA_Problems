Logic -> 

Approach -> 




// 1st Variant in which you have to check the next smaller element in an array circularly where output for the last element is not necessarily -1 you will have to check for every other
// element starting from the right

// -> tarverse the array from 2n -1 to 0 and change i to i % n 









// 2nd Variant in which you dont have to check circularly in the array that is answer for the last element is -1 
// Optimised Approach TC O(N) SC O(N)

vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--){
            int curr = arr[i];
            
            while(!st.empty() && curr <= st.top()){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
            }
            
            st.push(curr);
        }
        
        return ans;
    } 






// // Brute Force TLE - Make an array of twice size and traverse it accordingly

// // Brute Force- Accepted
// // create a vector ans iterate over nums and compare it with next elements circularly and push if there exists a greater element else push -1
// // TC O(N^2) OC O(N) using vector
    
vector<int> help_classmate(vector<int> arr, int n) {    
    vector<int> ans(n, -1);
        for(int i = 0; i < n ; i++){   
            int num = nums[i];         
            for(int j = i + 1; j < n; j++){
                
                if(nums[j] < num){
                    ans[i] = nums[j];
                    break;
                }
            }
        }
    return ans;
}