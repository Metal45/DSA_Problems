#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data = val;
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

// HD -> Horizontal distance

void printTopView(TreeNode *root){
    if(root == NULL){
        return;
    }

    map<int, int> topNode;
    queue<pair<TreeNode*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair <TreeNode*, int> temp = q.front();
        q.pop();

        TreeNode *currNode = temp.first;
        int HD = temp.second;

        if(topNode.find(HD) == topNode.end()){
            topNode[HD] = currNode -> data;
        }
        
        if(currNode -> left){
            q.push(make_pair(currNode -> left, HD - 1));
        }

        if(currNode -> right){
            q.push(make_pair(currNode -> right, HD + 1));
        }
    }

    for(auto i : topNode){
        cout << i.second << " ";
    }
}

int main(){
    TreeNode *root = buildTreeLevelOrder();
    printTopView(root);
}