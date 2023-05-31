#include <bits/stdc++.h>
using namespace std;

// famous pattern -> you push everything in the heap. Select some out, perform some operations and push them back until some condition is reached
// minimum cost to cut the rope

// -> approach -> T.C -> O(LogN) SC -> O(L) -> L -> (number of distinct charcters)
// You count the occurance of character, and sotre the character and their count in the maxHeap 
// the idea is to put the different characters adjacent to each other and use the the two most occurant characters every time so to use it as fast as possible
// at the end after utilizing all the characters if the last character has the freq > 1 then it is not possible to rearrange as they would be adjacent else you have it

class node {
    public:
    char ch;
    int freq;

    node(char d, int c) {
        ch = d;
        freq = c;
    }
};

class compare {
    public:
    bool operator()(node *a, node *b) {
        return a -> freq < b -> freq;
    }
};

class Solution {
public: 
    string reorganizeString(string s) {
        // counting occurances
        int arr[26] = {0};
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            arr[ch - 'a']++;
        }
        
        priority_queue<node*, vector<node*>, compare> maxHeap;

        // storing characters and their count in the max Heap
        for(int i = 0; i < 26; i++){ // O(N)
            if(arr[i] != 0){
                node *temp = new node(i + 'a', arr[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        // doing this until only one or no character is left
        while(maxHeap.size() > 1){ // -> O(N/2)
            // removing two most occurant characters
            node *first = maxHeap.top();
            maxHeap.pop();

            node *second = maxHeap.top();
            maxHeap.pop();

            // placing them adjacent
            ans += first -> ch;
            ans += second -> ch;

            // decreasing their frequency by 1
            (first -> freq)--;
            (second -> freq)--;

            // pushing them back
            if(first -> freq != 0){ // -> O(logN)
                maxHeap.push(first);
            }

            if(second -> freq != 0){
                maxHeap.push(second);
            }
        }

        // checking if their is any character in the heap
        if(maxHeap.size() == 1){
            node *last = maxHeap.top();
            maxHeap.pop();

            if(last -> freq > 1){
                return "";
            }else{
                ans += last -> ch;
            }
        }

        return ans;
    }
};
 