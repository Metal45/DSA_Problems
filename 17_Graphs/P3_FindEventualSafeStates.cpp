#include <bits/stdc++.h>
using namespace std;

// BFS Kahn's Algorithm
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    vector<int> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < graph[i].size(); j++){
            adj[graph[i][j]].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> pending;

    for(int i = 0; i < inDegree.size(); i++){
        if(inDegree[i] == 0){
            pending.push(i);
        }
    }

    while(!pending.empty()){
        int safeNode = pending.front();
        pending.pop();
        ans.push_back(safeNode);

        for(auto nbr : adj[safeNode]){
            inDegree[nbr]--;
            if(inDegree[nbr] == 0){
                pending.push(nbr);
            }
        }
    }
    
    sort(ans.begin(), ans.end());

    return ans;
}


// dfs solution
bool dfs(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack){
    visited[src] = true;
    inStack[src] = true;

    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            if(dfs(nbr, adj, visited, inStack)){
                return true;
            }
        }else if(inStack[nbr]){
            return true;
        }
    }

    inStack[src] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n), inStack(n);
    vector<int> ans;


    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, graph, visited, inStack);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!inStack[i]){
            ans.push_back(i);
        }
    }

    return ans;
}