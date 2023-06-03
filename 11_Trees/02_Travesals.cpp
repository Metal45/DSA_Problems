#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        this -> data = data;
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

// single line level order traversal
void LevelOrder(TreeNode *root){
    queue<TreeNode*> pending;
    pending.push(root);

    while(!pending.empty()){
        TreeNode *top = pending.front();
        pending.pop();

        cout << top -> data << " ";

        if(top -> left != NULL){
            pending.push(top -> left);
        }

        if(top -> right != NULL){
            pending.push(top -> right);
        }
    }
}

// Level order tarversal with levels in different lines 
// Here null represents the end of a level so you have to do two things once you encounter a NULL
// 1. -> cout << endl;
// 2. -> push a new NULL node int the queue. why? because since the level is completed so all the child nodes of this level are in queue so pushing NULL would be the end of that level
// Remeber -> Push NULL only when the queue is not empty as empty queue represents end of the tree so pushing NULL further will get you stuck in an infinite loop


void LevelOrder2(TreeNode *root){
    queue<TreeNode*> pending;
    pending.push(root);
    pending.push(NULL); // end of the first level will be after only one node

    while(!pending.empty()){
        TreeNode *top = pending.front();
        pending.pop();

        if(top != NULL){
            cout << top -> data << " ";

            if(top -> left != NULL){
                pending.push(top -> left);
            }

            if(top -> right != NULL){
                pending.push(top -> right);
            }
            
        }else{ // end of one level
            cout << endl;
            if(!pending.empty()){
                pending.push(NULL);
            }
        }
    }
}




// another way of printing level order traversal with levels in different lines
// -> remember the count of nodes in each level and while popping reduce the count 
// -> when count becomes zero it represents end of a level and count of nodes in the next level is equal to size of queue

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



// Inorder Traversal -> LNR

void Inorder(TreeNode *root){
    if(root == NULL){
        return ;
    }

    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
}

// Preorder Traversal -> NLR

void Preorder(TreeNode *root){
    if(root == NULL){
        return ;
    }

    cout << root -> data << " ";
    Inorder(root -> left);
    Inorder(root -> right);
}

// PostOrder Traversal -> LRN

void Postorder(TreeNode *root){
    if(root == NULL){
        return ;
    }

    Inorder(root -> left);
    Inorder(root -> right);
    cout << root -> data << " ";
}

int main(){
    TreeNode *root = buildTree();
    LevelOrder3(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Preorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
}