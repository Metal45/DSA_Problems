#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }
};

bool bfs(int src, unordered_map<int, list<int>> adj, map<int, bool> &visited){
    queue<pair<int, int>> pending;
    pending.push({src, -1});
    visited[src] = true;

    while(!pending.empty()){
        int top = pending.front().first;
        int parent = pending.front().second;
        pending.pop();

        for(auto i : adj[top]){
            if(!visited[i]){
                pending.push({i, top});
                visited[i] = true;
            }else if(visited[i] && i != parent){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(unordered_map<int, list<int>> adj, map<int, bool> &visited){
    for(auto i : adj){
        if(!visited[i.first] && bfs(i.first, adj, visited)){
            return true;
        }
    }

    return false;
}

int main(){

}


// // gfg ques

//     bool bfs(int src, vector<int> adj[], map<int, bool> &visited){
//         queue<pair<int, int>> pending;
//         pending.push({src, -1});
//         visited[src] = true;
        
//         while(!pending.empty()){
//             int curr_node = pending.front().first;
//             int parent = pending.front().second;
//             pending.pop();
            
//             for(auto neighbour : adj[curr_node]){
//                 if(!visited[neighbour]){
//                     pending.push({neighbour, curr_node});
//                     visited[neighbour] = true;
//                 }else if(visited[neighbour] && parent != neighbour){
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }
    
    
//     bool isCycle(int V, vector<int> adj[]) {
//         map<int, bool> visited;
        
//         for(int i  = 0; i < V; i++){
//             if(!visited[i]){
//                 if(bfs(i, adj, visited)){
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }