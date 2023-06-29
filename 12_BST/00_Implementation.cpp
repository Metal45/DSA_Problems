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

BSTNode *insertintoBST(BSTNode* root, int val){
    if(root == NULL){
        root = new BSTNode(val);
        return root;
    }

    if(val < root -> data){
        root -> left = insertintoBST(root -> left, val);
    }

    else{
        root -> right = insertintoBST(root -> right, val);
    }

    return root;
}

BSTNode* takeInput(BSTNode* &root){
    int val;
    cin >> val;
    while(val != -1){
        root = insertintoBST(root, val);
        cin >> val;
    }

    return root;
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

void preOrder(BSTNode *root){
    if(root == NULL){
        return ;
    }

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(BSTNode *root){
    if(root == NULL){
        return ;
    }

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void postOrder(BSTNode *root){
    if(root == NULL){
        return ;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}


int main(){
    BSTNode *root = NULL;
    root = takeInput(root);
    cout << "Level Order: " << endl;
    LevelOrder(root);

    cout << endl;

    cout << "Preorder: " << endl;
    preOrder(root);
    cout << endl;

    cout << "Inorder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "Postorder: " << endl;
    postOrder(root);
    cout << endl;
}