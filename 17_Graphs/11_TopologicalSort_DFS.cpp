// What happens when you do topological sort in a cyclic graph?
// how to find cycle in a directed graph using topological sort


#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &temp){
    
    visited[src] = true;
    
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs(nbr, adj, visited, temp);
        }
    }
    
    temp.push_back(src);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, adj, visited, ans);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}