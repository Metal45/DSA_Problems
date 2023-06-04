// Find the lowest common ancestor of the given two nodes 


// Brute force -> for each node store the path of root node to the target node 
// traverse the path until common nodes and the last common node in the path is the LCA

// TC -> O(N) N -> number of nodes
// SC -> O(N) -> to store the path

class Solution {
public:
    bool getPath(TreeNode *root, TreeNode *x, vector<TreeNode*> &Path){
        if(root == NULL){
            return false;
        }

        Path.push_back(root);

        if(root == x){
            return true;
        }

        bool leftAns = getPath(root -> left, x, Path);
        bool rightAns = getPath(root -> right, x, Path);

        if(leftAns || rightAns){
            return true;
        }

        Path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> Pathp;
        vector<TreeNode*> Pathq;

        getPath(root, p, Pathp);
        getPath(root, q, Pathq);

        int i = 0, j = 0;
        TreeNode *ans;

        while(i < Pathp.size() && j < Pathq.size()){
            if(Pathp[i] == Pathq[i]){
                ans = Pathp[i];
            }else{
                break;
            }

            i++, j++;
        }

        return ans;
    }
};


// Optimal Solution -> 

// A CA is node whose either left, right or both subtrees contains p and q as it is the ancestor of both and we have to find the lowest CA that is the first node from leaf to root for which the left and right subtree have p and q 
// A node can be considered an ancestor of itself 


// there are 4 possibile cases for a node 
// i) the node itself is p or q
// ii) either of the subtree contains one node each
// iii ) both of the nodes are in one subtree either left or right 
// iv) neither of the subtrees contains the nodes



// Approach -> i) traverse on the tree 
//            ii) if you encounter the root either p or q return the root -> (it represents the LCA till then that is the root itself)
//           iii) if it is not the root, search in the left subtree and the right subtree 
//            iv) if you reach NULL return NULL
//             v) now there arise 4 cases for a node -> (What you return in each case is the LCA till that call)
//                   1. both leftans and the rightans are NULL ->(neither of the nodes were present in the left and right subtree of this node). You return NULL in this case.
//                   2. the leftans is Null and the rightans exists ->(either one or both of the nodes are present in the right subtree of this node). You return rightans in this case 
//                   3. the leftans exists and the rightans is NULL ->(either one or both of the nodes are present in the left subtree of this node). You return leftans in this case 
//                   4. both leftans and rightans exists ->(both the subtrees contains one node each). You return root in this case 

// TC -> O(N) , SC -> O(N) (No extra space to store the ans)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode *leftAns = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root -> right, p, q);

        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else{ 
            return root;
        }
    }