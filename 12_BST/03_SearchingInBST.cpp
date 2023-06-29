#include <iostream>
using namespace std;

class BSTNode{
    public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int val){
        this -> data = val;
        left = NULL;
        right = NULL;
    }
};

bool searchinBST(BSTNode *root, int val){
    if(root == NULL){
        return false;
    }

    if(root -> data == val){
        return true;
    }

    bool leftAns;
    bool rightAns;

    if(root -> data > val){
        leftAns = searchinBST(root -> left, val);
    }else{
        rightAns = searchinBST(root -> right, val);
    }

    return leftAns || rightAns;
}


// LEETCODE 
BSTNode* searchBST(BSTNode* root, int val) {
    if(root == NULL){
        return NULL;
    }

    if(root -> data == val){
        return root;
    }
    
    if(root -> data > val){
        return searchBST(root -> left, val);
    }else{
        return searchBST(root -> right, val);
    }

}

int main(){

}