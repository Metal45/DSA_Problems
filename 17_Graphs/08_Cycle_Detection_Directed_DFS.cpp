#include <bits/stdc++.h>
using namespace std;

// Gfg throws TLE if you use maps, to avoid it you should use vectors

class Solution {
  public:
    bool dfs(int src, vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
            
        visited[src] = true;
        dfsVisited[src] = true;
        
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                
                bool nextAns = dfs(nbr, adj, visited, dfsVisited);
                
                if(nextAns){
                    return true;
                }
                
            }else if(visited[nbr] && dfsVisited[nbr]){
                    return true;
            }
            
        }
        
        dfsVisited[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited, dfsVisited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, dfsVisited)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};