#include <bits/stdc++.h>
using namespace std;

// Approach 1 ->     
// using min heap -> Put all distances with their co ordinates and pop k minimum distances and store their co ordinates


class node{
    public:
    int x, y;
    double dis;

    node(int x, int y){
        this -> x = x;
        this -> y = y;
        dis = sqrt((x*x) + (y*y)); 
    }
};

class compare{
    public:
    bool operator()(node *a, node *b){
        return a -> dis > b -> dis;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<node*, vector<node*>, compare> minHeap;
        // N -> Points size
        // O(NlogN) ~ O(N)
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            node *temp = new node(x, y);

            minHeap.push(temp);
        }

        vector<vector<int>> ans;

        // O(KlogN) ~ O(K)-> Removing k elements from heap (1 takes log N time)
        for(int i = 0; i < k; i++){
            node *temp = minHeap.top();
            minHeap.pop();
            vector<int> curr;
            curr.push_back(temp -> x);
            curr.push_back(temp -> y);
            ans.push_back(curr);
        }

        return ans;
    }
};


// Approach 2 -> Using MaxHeap (Better Space O(K) than min Heap O(N)) 
// TC -> O(NlogK)

// usign maxHeap instead of minHeap improves space from O(N) to O(K)
// 1. using max heap -> Put first distances with their co ordinates
// 2. for rest of the points if the dis is less than the max dis in the heap push it in else do nothing.
// 3. now the left points are the first k smallest points

class node{
    public:
    int x, y;
    double dis;

    node(int x, int y){
        this -> x = x;
        this -> y = y;
        dis = sqrt((x*x) + (y*y)); 
    }
};

class compare{
    public:
    bool operator()(node *a, node *b){
        return a -> dis < b -> dis;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<node*, vector<node*>, compare> minHeap;
        // N -> Points size
        // O(KlogK) ~ O(K)
        for(int i = 0; i < k; i++){
            int x = points[i][0];
            int y = points[i][1];

            node *temp = new node(x, y);

            minHeap.push(temp);
        }

        vector<vector<int>> ans;
        
        // O((n - k)logk)-> pushing n - k elements in heap in worst case heap (1 takes logk time)
        for(int i = k; i < points.size(); i++){ 
            int x = points[i][0];
            int y = points[i][1];

            double dis = sqrt((x*x) + (y*y)); 
            if(dis < minHeap.top() -> dis){
                node *temp = new node(x, y);
                minHeap.push(temp);
                minHeap.pop();
            }
        }

        for(int i = 0; i < k; i++){
            node *temp = minHeap.top();;
            minHeap.pop();
            vector<int> curr;
            curr.push_back(temp -> x);
            curr.push_back(temp -> y);
            ans.push_back(curr);
        }

        return ans;
    }
};

