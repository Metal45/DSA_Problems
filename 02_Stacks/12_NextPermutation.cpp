
// you have to find the next greater and smallest string of all next permutations

// Approach -> TC O(N) SC O(1)
    // Logic/ Observation - Last se chalu karke dekhna hai ki swap karke usse bada number ban skta hai kya? uske liye i -1 digit should be less than i 
    // find that digit and swap it with the next greater digit you will have your number
    
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        long long ans = 0;
        int ind = -1;
        int i = N - 1;
        // finding the i - 1 digit that is less than i 
        for(; i > 0; i--){
            if(arr[i] > arr[i - 1]){
                ind = i - 1;
                break;
            }
        }
        if(ind == -1){
            // if no such digit exists returning the reversed string 
            reverse(arr.begin(), arr.end());
            return arr;
        }else{
            // finding the next next greater digit
            for(int j = ind; j < N; j++){
                if(arr[j] > arr[ind]){
                    i = j;
                }
            }
            
            // swapping the digits
            swap(arr[ind], arr[i]);
            
            // reversing the string from the next index of the swapped digit it will be the shortest possible string as it will be in the reversed sorted order
            //as you have to find the next greater and smallest string of all next permutations
            reverse(arr.begin() + ind + 1, arr.end());
        }
        
        return arr;
    }