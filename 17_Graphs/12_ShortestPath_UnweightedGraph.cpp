// we can use BFS to find the shortest path in an unweighted graph or graph with unit weight

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


void shortestPathUsingBFS(int src, int des, unordered_map<int, list<int>> &adj){
    queue<int> pending;
    vector<int> parent(adj.size());
    vector<bool> visited(adj.size(), 0);

    parent[src] = -1;
    pending.push(src);

    while(!pending.empty()){    
        int top = pending.front();
        cout << top << " ";
        visited[top] = true;
        pending.pop();

        for(auto nbr: adj[top]){
            if(!visited[nbr]){
                pending.push(nbr);
                parent[nbr] = top;
            }
        }
    }

    cout << endl;

    vector<int> path;
    path.push_back(des);
    int currParent = parent[des];

    while(currParent != -1){
        path.push_back(currParent);
        currParent = parent[currParent];
    }

    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
}

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(0, 6, 1);
    g.addEdge(0, 5, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
    g.addEdge(8, 4, 1);
    g.printAdj();
    shortestPathUsingBFS(0, 4, g.adj);
}
