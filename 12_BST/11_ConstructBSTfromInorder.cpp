// You are given inorder traversal, construct a BST from inorder traversal

// Approach -> O(N) as we are creating a node for every element in the inorder array
// 1. go to the mid ((s + e)/2) element and make that the root node (to maintain the property of bst)
// 2. all the elements to the left of mid will be in the left subtree and will be smaller as the inorder is sorted 
// 3. all the elements to the right of mid will be in the right subtree and will be greater as the inorder is sorted
// 4. recursively call the fucntion for the left and right of mid 
// 5. the tree created will be a balanced binary search tree as the difference of nodes to left and right of root will be <= 1 as we are making mid the root node


#include <bits/stdc++.h>
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


BSTNode *Construct(vector<int> inorder, int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = s + (e - s)/2;

    BSTNode *newNode = new BSTNode(inorder[mid]);

    newNode -> left = Construct(inorder, s, mid - 1);
    newNode -> right = Construct(inorder, mid + 1, e);

    return newNode;
}


void LevelOrder(BSTNode *root){
    queue<BSTNode*> pending;
    pending.push(root);
    int count = 1;

    while(!pending.empty()){
        BSTNode *top = pending.front();
        pending.pop();
        count--;
        
        cout << top -> data << " ";

        if(top -> left){
            pending.push(top -> left);
        }

        if(top -> right){
            pending.push(top -> right);
        }

        if(!count){ // end of a level 
            cout << endl;
            count = pending.size(); // count of nodes in next level
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> inorder(n, 0);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        inorder[i] = temp;
    }

    BSTNode *root = Construct(inorder, 0, inorder.size() - 1);
    LevelOrder(root);
}