
// anticlockwise traversal of boundary nodes of a binary tree
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 


class Solution {
public:
    void fillLeftNodes(Node *root, vector<int> &leftNodes) {
        if(root == NULL) {
            return ;
        }    
        
        if(root -> left == NULL && root -> right == NULL) {
            return ;
        }
        
        leftNodes.push_back(root -> data);
        
        if(root -> left) {
            fillLeftNodes(root -> left, leftNodes);
        }
        else if(root -> right) {
            fillLeftNodes(root -> right, leftNodes);
        }
    }
    
    void fillLeaves(Node *root, vector<int> &leaf) {
        if(root == NULL) {
            return ;
        }
        
        if(root -> left == NULL && root -> right == NULL) {
            leaf.push_back(root -> data);
            return ;
        }
        
        fillLeaves(root -> left, leaf);
        fillLeaves(root -> right, leaf);
    }
    
    void fillRightNodes (Node *root, vector<int> &rightNodes) {
        if(root == NULL) {
            return ;
        }    
        
        if(root -> left == NULL && root -> right == NULL) {
            return ;
        }
        
        rightNodes.push_back(root -> data);
        
        if(root -> right) {
            fillRightNodes(root -> right, rightNodes);
        }
        else if(root -> left) {
            fillRightNodes(root -> left, rightNodes);
        }
    }
     
    vector <int> boundary(Node *root){
        if(root == NULL) {
            return {};
        }
        
        if(root -> left == NULL && root -> right == NULL) {
            return {root -> data};
        }
        
        vector<int> ans;
        ans.push_back(root -> data);
        
        vector<int> leftNodes, leaf, rightNodes;
        
        if(root -> left) {
            fillLeftNodes(root -> left, leftNodes);
        }
        
        fillLeaves(root, leaf);
        
        if(root -> right) {
            fillRightNodes(root -> right, rightNodes);
        }
        
        for(auto i: leftNodes) {
            ans.push_back(i);
        }
        
        for(auto i : leaf) {
            ans.push_back(i);
        }
        
        reverse(begin(rightNodes), end(rightNodes));
        for(auto i : rightNodes) {
            ans.push_back(i);
        }
        
        return ans;
    }
    
};