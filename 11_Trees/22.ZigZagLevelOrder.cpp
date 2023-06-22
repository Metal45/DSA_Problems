// Appproach -> It is simple as the normal level order traversal, you just have to 
// alternatively reverse the answer before pushing it back
// you can do that by either maintaing a direction variable or on alternative levels (odd levels)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> pending;
        pending.push(root);
        int count = 1;
        int dir = 1;

        while(!pending.empty()){
            TreeNode *top = pending.front();
            pending.pop();
            count--;
            
            temp.push_back(top -> val);

            if(top -> left){
                pending.push(top -> left);
            }

            if(top -> right){
                pending.push(top -> right);
            }

            if(!count){
                if(dir == -1)
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                count = pending.size();
                dir = -dir;
            }
        }


        return ans;
    }
};