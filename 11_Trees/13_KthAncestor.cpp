// find the Kth Ancestor of the given node in the binary tree 

// Why is Approach not working


// Approach 1 -> i) Find and store the path of the given node
//              ii) From the given node just find the kth node from the last which is the kth Ancestor which is (N - k - 1)

bool getPath(Node *root, int node, vector<Node*> &path){
    if(root == NULL){
        return false;
    }
    
    path.push_back(root);
    
    if(root -> data == node){
        return true;
    }
    
    bool leftans = getPath(root -> left, node, path);
    bool rightans = getPath(root -> right, node, path);
    
    if(leftans || rightans){
        return true;
    }
    
    path.pop_back();
    return false;
    
}

int kthAncestor(Node *root, int k, int node)
{
    vector<Node*> path;
    bool ans = getPath(root, node, path);
    
    int i  = path.size() - k - 1;
    if(i < 0){
        return -1;
    }else{
        return path[i] -> data;
    }
}



// Approach 2 -> 

int ans = -1;

bool solve(Node *root, int &k, int node){
    
    if(root == NULL){
        return false;
    }
    
    if(root -> data == node){
        return true;
    }
    
    
    bool leftans = solve(root -> left, k, node);
    bool rightans = solve(root -> right, k, node);
    
    if(leftans || rightans){
        k--;
    }
    
    if(k == 0){
        k = -1;
        ans = root -> data;
    }
    
    return leftans || rightans;
}

int kthAncestor(Node *root, int k, int node)
{
    bool check = solve(root, k, node);
    return ans;
}
