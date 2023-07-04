#include <bits/stdc++.h>
using namespace std;

// Approach ->

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

class Solution
{
    public:
    void fillInorder(Node *root, vector<int> &inorder){
        if(root == NULL){
            return ;
        }
        
        fillInorder(root -> left, inorder);
        inorder.push_back(root -> data);
        fillInorder(root -> right, inorder);
    }
    
    vector<int> mergeArrays(vector<int> arr1, vector<int> arr2){
        
        int i = 0, j = 0, k = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> arr3(n1 + n2, 0);
     
        while (i<n1 && j <n2){
            if (arr1[i] < arr2[j])
                arr3[k++] = arr1[i++];
            else
                arr3[k++] = arr2[j++];
        }
     
        while (i < n1)
            arr3[k++] = arr1[i++];
     

        while (j < n2)
            arr3[k++] = arr2[j++];
            
        
        return arr3;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        // O(max(M, N))
       vector<int> inorder1, inorder2;
       fillInorder(root1, inorder1);
       fillInorder(root2, inorder2);
       
       // O(M + N)
       vector<int> ans = mergeArrays(inorder1, inorder2);
       return ans;
    }
};