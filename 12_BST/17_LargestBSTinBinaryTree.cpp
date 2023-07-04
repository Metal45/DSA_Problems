#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool isValid;
    
    NodeData(){
        
    }
    
    NodeData(int size, int min, int max, bool isValid){
        this -> size = size;
        minVal = min;
        maxVal = max;
        this -> isValid = isValid;
    }
};

// Approach ->  TC O(N) SC O(H)
// 

class Solution{
    public:
    
    NodeData solve(Node *root){
        if(root == NULL){
            NodeData temp(0, INT_MAX, INT_MIN, true);
            return temp;
        }
        
        NodeData leftAns = solve(root -> left);
        NodeData rightAns = solve(root -> right);
        
        NodeData currNodeAns;
        
        // we have to include root -> data for the base case else the maxVal will always be the rightAns.maxVal
        // and the minVal will be leftAns.minVal
        currNodeAns.maxVal = max(root -> data, rightAns.maxVal);
        currNodeAns.minVal = min(root -> data, leftAns.minVal);
        
        if(leftAns.isValid && rightAns.isValid && (root -> data > leftAns.maxVal) && (root -> data < rightAns.minVal)){
            currNodeAns.isValid = true;
            currNodeAns.size = leftAns.size + rightAns.size + 1;
            
        }else{
            currNodeAns.isValid = false;
            currNodeAns.size = max(leftAns.size, rightAns.size);
        }
        
        return currNodeAns;
    }
    
    int largestBst(Node *root)
    {
    	NodeData temp = solve(root);
    	return temp.size;
    }
};

// Another way -> Only a minor change in way of storing the answer

class Solution{
    public:
    NodeData solve(Node *root, int &ans){
        if(root == NULL){
            NodeData temp(0, INT_MAX, INT_MIN, true);
            return temp;
        }
        
        NodeData leftAns = solve(root -> left, ans);
        NodeData rightAns = solve(root -> right, ans);
        
        NodeData currNodeAns;
        
        currNodeAns.size = leftAns.size + rightAns.size + 1;
        currNodeAns.maxVal = max(root -> data, rightAns.maxVal);
        currNodeAns.minVal = min(root -> data, leftAns.minVal);
        
        if(leftAns.isValid && rightAns.isValid && (root -> data > leftAns.maxVal) && (root -> data < rightAns.minVal)){
            currNodeAns.isValid = true;
            
        }else{
            currNodeAns.isValid = false;
        
        }
        
        if(currNodeAns.isValid){
            ans = max(ans, currNodeAns.size);
        }
        
        return currNodeAns;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = INT_MIN;
    	NodeData temp = solve(root, ans);
    	return ans;
    }
};