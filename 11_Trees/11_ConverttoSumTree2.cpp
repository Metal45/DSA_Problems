// Convert a given tree to a tree where every node contains sum of values of current node, left and right subtrees

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


TreeNode *buildTreeLevelOrder(){
    cout << "Enter of Root Data: ";
    int rootData;
    cin >> rootData;

    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode*> pending;
    pending.push(root);

    while(!pending.empty()){
        TreeNode *top = pending.front();
        pending.pop();

        int Ldata;
        cout << "Enter Left Node of "<<top -> data<<": ";
        cin >> Ldata;

        if(Ldata != -1){
            TreeNode *leftChild = new TreeNode(Ldata);
            top -> left = leftChild;
            pending.push(leftChild);
        }

        int Rdata;
        cout << "Enter Right Node of "<<top -> data<<": ";
        cin >> Rdata;

        if(Rdata != -1){
            TreeNode *rightChild = new TreeNode(Rdata);
            top -> right = rightChild;
            pending.push(rightChild);
        }
    }

    return root;
}

void LevelOrder3(TreeNode *root){
    queue<TreeNode*> pending;
    pending.push(root);
    int count = 1;

    while(!pending.empty()){
        TreeNode *top = pending.front();
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

int sum(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    return root -> data + sum(root -> left) + sum(root -> right);
}

void convert(TreeNode *root){
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        return ;
    }
    
    root -> data = root -> data + sum(root -> left) + sum(root -> right);
    
    convert(root -> left);
    convert(root -> right);
}

void convert2(TreeNode *root){
    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL){
        return ;
    }

    convert2(root -> left);
    convert2(root -> right);

    int left = (root -> left != NULL) ? root -> left -> data : 0;
    int right = (root -> right != NULL) ? root -> right -> data : 0;
    
    root -> data = root -> data + left + right;
}

int main(){
    TreeNode *root = buildTreeLevelOrder();
    LevelOrder3(root);
    cout << endl;
    convert2(root);
    LevelOrder3(root);
}
   