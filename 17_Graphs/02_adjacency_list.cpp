#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;

    // adding edges to the graph
    void addEdge(int u, int v, bool direction){

        // adding edge u -> v
        adj[u].push_back(v);

        // if undirected also adding v -> u
        if(!direction){
            adj[v].push_back(u);
        }
    }

    // printing the adjList of the graph
    void printAdj(){
        for(auto node: adj){
            cout << node.first << "-> ";

            for(auto j: node.second){
                cout << j << " ";
            }

            cout << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);
    g.printAdj();
}