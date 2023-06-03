// people usually make mistakes while doing this question -> One important questions

// A happy string a string in which no more than 2 same characters are adjacent 
// Approach 1-> 
// 1. push the characters and their count in heap 
// 2. extract two different characters with the max count 
// 3. you can put at max two same characters adjacent so if the freq is >= 2 so choose it and add it two times and reduce its frequency by 2 
// 4. do same for the second character also but when second.count >= first.count
// 5. by doing this no more than two character will be adjacent


#include <bits/stdc++.h>
using namespace std;


class node {
    public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node, vector<node>, compare> maxHeap;

        if(a > 0){
            node first('a', a);
            maxHeap.push(first);
        }
        
        if(b > 0){
            node second('b', b);
            maxHeap.push(second);
        }
        
        if(c > 0) {
            node third('c', c);
            maxHeap.push(third);
        }

        string ans = "";

        while(maxHeap.size() > 1){
            node first = maxHeap.top();
            maxHeap.pop();

            node second = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2){
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }else{
                ans += first.data;
                first.count--;
            } 
           
            // -> Important Condition -> Do not forget -> Optimal Answer  BUT WHY?
            if(second.count >= 2 && second.count >= first.count){
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }else{
                ans += second.data;
                second.count--;
            } 

            if(first.count > 0){
                maxHeap.push(first);
            }

            if(second.count > 0){
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1){
            node first = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2){
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }else{
                ans += first.data;
                first.count--;
            } 
        }

        return ans;
    }
};



// Approach -> 2 
// Greedy Approach ->
// 1. we will use the most occuring character and will append it in the answer string while checking that last two characters are not the same
// 2. if the last two characters are same we will append a the second most occuring character 
// 3. if we can not append the second most occuring character it signifies it is the longest possible happy string possible and will break out of the loop

class node {
    public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node, vector<node>, compare> maxHeap;

        if(a > 0){
            node first('a', a);
            maxHeap.push(first);
        }
        
        if(b > 0){
            node second('b', b);
            maxHeap.push(second);
        }
        
        if(c > 0) {
            node third('c', c);
            maxHeap.push(third);
        }

        string ans = "";

        while(maxHeap.size() > 0){
            node first = maxHeap.top();
            maxHeap.pop();

            if(ans.size() >= 2 && (ans[ans.size() - 1] == first.data && ans[ans.size() - 2] == first.data)){
                if(!maxHeap.empty()){
                    node second = maxHeap.top();
                    maxHeap.pop();
                    ans += second.data;
                    second.count--;
                    if(second.count > 0)
                    maxHeap.push(second);
                }else{
                    break;
                }
            }else{
                ans += first.data;
                first.count--;
            }

            if(first.count > 0){
                maxHeap.push(first);
            }        
        }

        return ans;
    }
};