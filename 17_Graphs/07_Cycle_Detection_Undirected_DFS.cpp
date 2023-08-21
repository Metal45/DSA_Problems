#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<int> adj[], unordered_map<int, bool> &visited, int parent){
    visited[src] = true;
    
    for(auto i : adj[src]){
        if(!visited[i]) {
            bool nextAns = dfs(i, adj, visited, src);
            if(nextAns == true){
                return true;
            }
        }else if(visited[i] && i != parent){
            return true;
        }
    }
    
    return false;
}
  
bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, -1)){
                return true;
            }
        }
    }
    
    return false;
}