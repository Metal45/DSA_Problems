#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int src, int parent, int timer, vector<int> &disc, vector<int> &low, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<vector<int>> &result){
        visited[src] = true;
        disc[src] = low[src] = timer++;

        for(auto nbr : adj[src]){
            if(nbr == parent) continue;
            else if(!visited[nbr]){
                dfs(nbr, src, timer, disc, low, adj, visited, result);
                low[src] = min(low[src], low[nbr]);
                if(low[nbr] > disc[src]){
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    result.push_back(temp);
                };
            }else{
                low[src] = min(low[src], disc[nbr]);
            }
        }
    }
    

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int timer = 0, parent = -1;
        vector<int> disc(n, -1), low(n, -1);
        vector<bool> visited(n, false);
        vector<vector<int>> result;
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, parent, timer, disc, low, adj, visited, result);
            }
        }

        return result;
    }
};