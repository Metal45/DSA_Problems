#include <bits/stdc++.h>
using namespace std;

// question : number of components in a graph
// Approach -> TC O(N2)
// 1. Every single bfs and dfs call covers one connected component 
// 2. make either bfs or dfs call for the graph and count the number of times bfs or dfs is called 
// 3. the number of calls made are the number of components / provinces the graph




// 1st way -> with the use of adjacency matrix

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



// 2nd way -> wihtout using adjacency matrix

// use row number as the node and col number as the neighbours and grid[src][col] == 1 signifies the edge between src and col
// taking row number as node, the col numbers as neighbours and checking if their exist edge between them and if edge exists (connected) calling dfs for that

class Solution {
public:

    void dfs(int src, int n, vector<vector<int>> &isConnected, vector<bool> &visited){
        visited[src] = true;

        for(int col = 0; col < n; col++){
            if(col != src && isConnected[src][col] == 1){
                if(!visited[col]){
                    dfs(col, n, isConnected, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0; 
        vector<bool> visited(n, 0);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, n, isConnected, visited);
            }
        }

        return count;
    }
};