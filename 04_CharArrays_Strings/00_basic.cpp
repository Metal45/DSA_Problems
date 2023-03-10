// character ranges from -128 to 127

// string is a datatype while char array is a data structure
// In a string you can not access the null character unlike char array



//  ->  Some important inbuilt functions of strings 

// to find a substring in a string 
// s.substr(a, b) -> starting from index a of size b

// to compare two strings 
// a.compare(b) == 0 then two strings are exactly same

// find a strating index of a substring in a string 
// s.find(substr)

// replace a substring starting from index i , length l with substrig str
// s.replace(i, l, str)

// to erase from a string
// 1. erase l char from string starting from i index
  // s.erase(i, l);

// to convert integer to string 
// stoi(), atoi() but these sometimes give int overflow 

// maximum element in a vector
// *max_element(v.begin(), v.end());

map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int count = 0;
        for(auto i: freq){
            if(freq.find(i.first + k) != freq.end()){
                i.sec
                ans++;
            }
        }
        return 0;

        #include<bits/stdc++.h>

        int t;
        cin >> t;
        while(t--){
            
        }





        
        // Brute Force -> Consider Each and every pair using two loops TC O(N2) SC O(1)

        // Better Approach -> HashMaps TC O(N) SC O(N) 
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int ans = 0;
    
        if(k != 0){
            for(auto i: freq){
                if(freq.find(i.first + k) != freq.end()){
                    i.second = 0;
                    ans++;
                }
            }
        }else{
            for(auto i : freq){
                if(i.second >= 2){
                    ans++;
                }
            }
        }
       
        return ans;