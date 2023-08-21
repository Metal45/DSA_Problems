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

    void BFStraversal(int src, map<int, bool> &visited){
        queue<int> pendingNodes;
        

        pendingNodes.push(src);
        visited[src] = true;

        while(!pendingNodes.empty()){

            int frontNode = pendingNodes.front();
            pendingNodes.pop();
            cout << frontNode << ", ";

            for(auto i: adj[frontNode]){
                if(!visited[i]){
                    pendingNodes.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }
};



int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(3,5,0);
    g.addEdge(1,3,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);


    // how to handle the case of disconnected graphs you loop for every node so if some node remains unvisited it will be visited
    map<int, bool> visited;
    for(int i = 0; i <= 7; i++){
        if(!visited[i]) {
            g.BFStraversal(0, visited);
        }
    }
}