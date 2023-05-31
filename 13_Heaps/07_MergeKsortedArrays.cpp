// Brute Force -> Put All elements of k arrays in one array and sort it
// -> O(nK) + O(nKlog(nK))

// Optmial -> Using heaps

// Merge K sorted arrays into a single array
// TC -> O(NKlogK)

#include <bits/stdc++.h>
using namespace std;

class data{
    public:
    int val;
    int row;
    int col;
    
    data(int val, int row, int col){
        this -> val = val;
        this -> row = row;
        this -> col = col;
    }
};

class cmp{
    public:
    bool operator()(data *a, data *b){
        return a -> val > b -> val;
    }
};


class Solution
{
    public:  
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    
    {
        vector<int> ans;
        priority_queue<data*, vector<data*>, cmp> minHeap;
        
        for(int i = 0; i < K; i++){ // O(KlogK)
            data *temp = new data(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        
        // O(nKlog(K))
        while(!minHeap.empty()){ // O(nk - k)
            data *curr = minHeap.top();
            int minimum = curr -> val;
            int minRow = curr -> row;
            int minCol = curr -> col;
            
            minHeap.pop();
            ans.push_back(minimum); // O(1)
            
            int newCol = minCol + 1;
            if(newCol < arr[0].size()){ // O(LogK)
                int nextElement = arr[minRow][newCol];
                data *next = new data(nextElement, minRow, newCol);
                minHeap.push(next);
            }
        }
        
        
        return ans;
    }
};