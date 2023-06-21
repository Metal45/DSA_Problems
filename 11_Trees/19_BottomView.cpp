// Same as Printing the top view of the binary tree you just have to overwrite the value of the horizontal distance 
// if you encounter a new node with the same horizontal distance unlike printing the top view

class Solution {
  public:
    void printBottomView(Node *root, vector<int> &ans){
        if(root == NULL){
            return;
        }
    
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
    
        q.push(make_pair(root, 0));
    
        while(!q.empty()){
            pair <Node*, int> temp = q.front();
            q.pop();
    
            Node *currNode = temp.first;
            int HD = temp.second;
    

            topNode[HD] = currNode -> data;
            
            
            if(currNode -> left){
                q.push(make_pair(currNode -> left, HD - 1));
            }
    
            if(currNode -> right){
                q.push(make_pair(currNode -> right, HD + 1));
            }
        }
    
        for(auto i : topNode){
            ans.push_back(i.second);
        }
    }
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        printBottomView(root, ans);
        return ans;
    }
};