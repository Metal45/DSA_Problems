#include <bits/stdc++.h>
using namespace std;

// question : number of components in a graph

void dfs(int src, vector<vector<int>> &adj, vector<bool> &visited){
    visited[src] = true;

    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs(nbr, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int count = 0;
    vector<vector<int>> adj(n);
    vector<bool> visited(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < isConnected[i].size(); j++){
            if(i != j && isConnected[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(i, adj, visited);
        }
    }

    return count;
}