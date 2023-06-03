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


TreeNode* buildTree(){
    int rootData;
    cin >> rootData;

    if(rootData == -1){
        return NULL;
    }

    TreeNode *root = new TreeNode(rootData);

    cout << "Eneter left node of " << rootData << ": ";
    root -> left = buildTree();

    cout << "Eneter left node of " << rootData << ": ";
    root -> right = buildTree();

    return root;
}

TreeNode *buildTree2(int val){
    if(val == -1){
        return NULL;
    }

    TreeNode *root = new TreeNode(val);
    int left;
    cout << "Eneter left node of " << root -> data << " ";
    cin >> left;
    root -> left = buildTree2(left);

    int right;
    cout << "Eneter right node of " << root -> data << ": ";
    cin >> right;
    root -> right = buildTree2(right);

    return root;
}

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

void printTree(TreeNode *root){
    if(root == NULL){
        cout << "-1 ";
        return ;
    }

    cout << root -> data << " ";
    printTree(root -> left);
    printTree(root -> right);
}

int main(){
    TreeNode *root = buildTreeLevelOrder();
    printTree(root);
}