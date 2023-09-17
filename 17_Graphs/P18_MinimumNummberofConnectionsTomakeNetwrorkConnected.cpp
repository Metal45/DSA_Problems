#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, unordered_map<int, list<int>> &adj, vector<bool> &visited){
        visited[src] = true;
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                dfs(nbr, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();

        // checking if the wires are sufficient 
        // you need atleast minimum n - 1 wires to connect n nodes
        if(n - 1 > e) return -1;

        unordered_map<int, list<int>> adj;
        vector<bool> visited(n, false);

        for(int i = 0; i < e; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }


        // counting the total disconnected Components 
        // since now we have sufficient wires 
        // the total operations / wires you need to connct these disconnected compnonents is -> components - 1
        // by connecting these components the whole network will be connected
         
        int disComponent = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                disComponent++;
                dfs(i, adj, visited);
            }
        }

        return disComponent - 1;
    }
};