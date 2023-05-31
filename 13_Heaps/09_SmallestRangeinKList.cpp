#include <bits/stdc++.h>
using namespace std;

// is Question ko code karne me log galti karte hai 

// -> You have to find the smallest range that consists at least one number form each sorted list

// Approach -> TC -> O(NlogK)  SC -> O(K) Heap
// 1.  consider first element of every array, these k elements given there are k sorted lists, contains one element from every list and the current range (min, max) of 
// 2.  selected k numbers, and now to decrease the range you can do two things either increase the min or decrease the max
// 3.  sicne the lists are sorted, you can only increase the min as the next number of min or max will be greater so max can not be decreased 
// 4.  now a new number is there and new range find the new minimum and maximum and check if the new range is smaller if yes store the new min and max else 
// 5.  again increase the new min 
// 6.  do this until any one of the arrays is finished (since we have to use element from each array we can not move further else the element of this array will not present)

// We will have to use minHeap to find the minimum element and maximum element can be calculated while storing the k elemnts and can be updated at the time of pushing new element 



// creating a class for the data to be stored in heap to keep a track of row and column of the element removed (minimum element) so the next element can be find
class node{
    public:
    int val, row, col;

    node(int val, int row, int col){
        this -> val = val;
        this -> row = row;
        this -> col = col;
    }
};


class cmp{
    public:
    bool operator()(node *a, node *b){
        return a -> val > b -> val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<node*, vector<node*>, cmp> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // storing the first element of every row for each row

        for(int i = 0; i < k; i++){ // O(K)

            // calculating the minimum and maximum element in the k numbers
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            node *temp = new node(nums[i][0], i, 0);
            minHeap.push(temp);
        }

        // first range -> (min, max)
        int ansStart = mini;
        int ansEnd = maxi;


        // O(NlogK)  (N -> size of the largest list)
        while(true){ // O(N)

            // removing the current minimum element from the heap 
            node *top = minHeap.top();
            minHeap.pop();

            // calculating the new row and column for increasing the minimum
            int newRow = top -> row;
            int newCol = top -> col + 1;

            // checking if the currnt list is finished or not
            if(newCol < nums[newRow].size()){

                // pushing the next element from the heap
                node *next = new node(nums[newRow][newCol], newRow, newCol);
                minHeap.push(next);  // -> O(logK)

                // updating the min and max and finding the new range

                maxi = max(maxi, nums[newRow][newCol]); // max can be updated by just checking if the new number is the new max or the last one
                mini = minHeap.top() -> val; // min will be at the top of the heap

                // checking if the new range is smaller or not
                if(ansEnd - ansStart > maxi - mini){
                    ansEnd = maxi;
                    ansStart = mini;
                } 
            }else{
                // breaking if the current list is finished
                break;
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);

        return ans;
    }
};


// another way -> same approach but the comparision of new range and upddation of min and max is done in different way
// dry run if you don't understand you will get it 

class node{
    public:
    int val;
    int row;
    int col;

    node(int val, int row, int col){
        this -> val = val;
        this -> row = row;
        this -> col = col;
    }
};

class cmp{
    public: 
    bool operator()(node *a, node *b){
        return a -> val > b -> val;
    } 
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, cmp> minHeap;

        for(int i = 0; i < k; i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            node *temp = new node(nums[i][0], i, 0);
            minHeap.push(temp);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        // we have to run this loop until any one of the array is finished
        while(!minHeap.empty()){
            node *curr = minHeap.top();
            minHeap.pop();
            int currmin = curr -> val;
            int currRow = curr -> row;
            int currCol = curr -> col;

            mini = currmin;

            if(ansEnd - ansStart > maxi - mini){
                ansStart = mini;
                ansEnd = maxi;
            }

            int newRow = currRow;
            int newCol = currCol + 1;
            
            if(newCol < nums[currRow].size()){
                maxi = max(maxi, nums[newRow][newCol]);
                node *newMini = new node(nums[newRow][newCol], newRow, newCol);
                minHeap.push(newMini);
            }else{
                break;
            }
        }

        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};