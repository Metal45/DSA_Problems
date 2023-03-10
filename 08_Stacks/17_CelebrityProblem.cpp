// Tell which person in the matrix is the celebrity 


// Optimised Approach -> TC O(N) Compare consequitve people if they know each other or not and eliminate them and verify 
// for the person left at the end by checking their row and column. You can do this using stack and by loop with SC of O(N) and O(1)
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        // // Using simple for loop SC O(1)
        // int i = 0;
        // int ans = i;
        // // cout << ans << endl;
        // for(; i < n - 1; i++){
        //     if(M[ans][i+1] == 1){
        //         ans = i + 1;
        //     }
        // }
        
        // Using stack space complexity SC O(N)
        stack<int> s;
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(M[a][b] == 1){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        int ans = s.top();
        int zeroCount = 0;
        
        
        // Row Check if all 0's are there
        for(int i = 0; i < n; i++){
            if(M[ans][i] == 0){
                zeroCount++;
            }
        }
        
        if(zeroCount != n){
            return -1;
        }
        
        
        int OneCount = 0;
        
        // Column check if all the 1's there
        for(int i = 0; i < n; i++){
            if(M[i][ans] == 1){
                OneCount++;
            }
        }
        
        if(OneCount != n - 1){
            return -1;
        }
        
        return ans;
    }





 // Logic -> The celebrity is known by everyone so the it will have all 1's in the column except it's own
        
    // Brute Approach -> TC O(N2) SC O(1) -> Iterate over the array with one loop checking the 1 in the column of that index(j) if that satisfies, check if that knows
    // somone else for that check if the row of that index has anything except 0 then its a celebrity

    int celebrity(vector<vector<int> >& M, int n) 
    {   
        bool isCeleb = 1;
        for(int j = 0; j < n; j++){
            
            for(int i = 0; i < n; i++){
                // skip when i == j as one knows himself
                if(i == j){
                    isCeleb = 1;
                    continue;
                }
                
                // checking if the j person is known by everyone else
                if(M[i][j] != 1){
                    isCeleb = 0;
                    break;
                }
            }
            
            if(isCeleb == 1){
                // checking if j knows anyone else
                for(int k = 0; k < n; k++){
                    
                    if(M[j][k] == 1){
                        isCeleb = 0;
                        break;
                    }
                }
                
                // if both the above conditions are true j is the celeb else we will check for the next person
                if(isCeleb == 1)
                return j;
            }
        }
        // No person presents is the celeb
        return -1;
    }