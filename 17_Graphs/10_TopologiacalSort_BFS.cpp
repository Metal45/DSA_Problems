#include <bits/stdc++.h>
using namespace std;

// topological sort using bfs (Kahn's algo)
// Kahn's algo - store nodes with indegree 0 in the queue

vector<int> topoSort(int V, vector<int> adj[]) 
{
    queue<int> pending;
    vector<int> ans;
    unordered_map<int, int> inDegree;
    
    // calculating indegree for every node
    for(int i = 0; i < V; i++){
        
        for(auto nbr : adj[i]){
            inDegree[nbr]++;
        }
        
    }
    
    // pushing nodes with indegree 0 inside queue
    // there is no need to use visited map because even for disconnected graph all the nodes with indegree 0 will be
    // pushed in queue with the for loop written below
    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0){
            pending.push(i);
        }
    }
    
    while(!pending.empty()){
        int front = pending.front();
        ans.push_back(front);
        pending.pop();
        
        for(auto nbr : adj[front]){
            inDegree[nbr]--;
            if(inDegree[nbr] == 0){
                pending.push(nbr);
            }
        }
    }
    
    
    return ans;
}
