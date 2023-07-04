// You have to implement a bst itreator that will start from root
// next will return the next element in the inorder tarversal 
// hasnext will return a boolean value if there exists a next element



// Approach 1 -> TC O(1) (next and hasnext, avg) SC O(N)
// Simply store the inorder traversal 
// and return the next element one by one
BSTIterator {
public:
    int ptr = 0;
    vector<int> inorder;

    void saveInorder(TreeNode *root){
        if(root == NULL) return;
        saveInorder(root -> left);
        inorder.push_back(root -> val);
        saveInorder(root -> right);
    }
    
    BSTIterator(TreeNode* root) {
        saveInorder(root);
    }
    
    int next() {
        return inorder[ptr++];
    }
    
    bool hasNext() {
        if(ptr >= inorder.size()){
            return false;
        }

        return true;
    }
};


// Approach 2 -> TC O(1) (next and hasnext, avg) SC O(h)
// 3 steps in order -> LEFT NODE RIGHT
// We won't save inorder in one time we will store partially -> First we will store left (1st step)
// when you pop Node (2nd Step) and then you go right (3rd step) and store till the leftmost node again (1st step) -> (It's like we do recursion in step)

// 1. Here to reduce the space complexity we will save partial inorder in stack
// 2. first we will store every node till the extreme left node 
// 3. now every time we pop the next element we go to right and repeat the 2 step 
// 4. if the stack is empty hasnext is false else true


// Dry run on leetcode test case 1 
// 1. stack -> [3, 7]
// 2. pop 3 -> (3 -> right(Null)) -> stack -> [7]
// 3. pop 7 -> stack (7 -> right (15) -> leftmost node) -> stack -> [9, 15];
// 4. pop 9 -> (9 -> right(Null)) -> stack -> [15]
// 5. pop 15 -> (15 -> right(20) -> leftmost node)  -> stack -> [20]
// 6. pop 20
// output -> 3 7 9 15 20


class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode *root){
        while(root != NULL){
            st.push(root);
            root = root -> left;
        }
    }

    int next() {
        TreeNode *front = st.top();
        st.pop();
        partialInorder(front -> right);
        return front -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};