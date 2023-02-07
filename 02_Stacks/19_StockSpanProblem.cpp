// Brute Force  TC O(N2) SC O(N) -> For each element in the array calculate the number of days having lesser or equal price than today
// by iterating over the array 


// Optimal Approach TC O(N) SC O(N) This problem is similar to finding next greatest element to left so find the price that is  first greater 
// to its left, you can do this using stack in O(N) time
    
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n);
       stack<int> s;
       
       // stroing 0 index to compare the price of 0 day with 1st 0
       s.push(0);
       
       // span of first element will be 1
       ans[0] = 1;
       
       // 1. find the next greater element to the left of curr 
       // 2. calulate the span 
       // if stack is empty no element is has a greater price span would be its index + 1
       // else the span would be its index - index of the prev greater, that is s.top();
       
       
       for(int i = 1; i < n; i++){
            while(!s.empty() && price[s.top()] <= price[i]){
                s.pop();
            }   
            
            if(!s.empty()){ 
                int span = i - s.top();
                ans[i] = span;
            }else{
                int span = i + 1;
                ans[i] = span;
            }
            
            s.push(i);
       }
       
       return ans;
    }