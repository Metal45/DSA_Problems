#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    void DFStraversal(int src, map<int, bool> &visited){
        cout << src << ", ";
        visited[src] = true;

        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                DFStraversal(neighbour, visited);
            }
        }
    }
};



int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);


    // how to handle the case of disconnected graphs you loop for every node so if some node remains unvisited it will be visited
    map<int, bool> visited;
    for(int i = 0; i < 5; i++){
        if(!visited[i]) {
            g.DFStraversal(0, visited);
        }
    }
}