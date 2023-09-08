// What does it state?
// How does it work?

// Why Floyd Warshall?
// Floyd warhsall is an algorithm used for finding all pair of shortest paths that is shortest path between every pair of vertices.


// What does it state?

// How does it work?

// Why BellmanFord when dijsktra?

#include <bits/stdc++.h>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, bool direction){
        adj[u].push_back({v, weight});
        if(direction){
            adj[v].push_back({u, weight});
        }
    }

    void printAdj(){
        for(auto node: adj){
            cout << node.first << "-> ";

            for(auto j: node.second){
                cout << "(" << j.first << ", " << j.second << ") ";
            }

            cout << endl;
        }
    }
};

void FloydWarshal(unordered_map<int, list<pair<int, int>>> adj, int n){
    vector<vector<int>> dis(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++){
        dis[i][i] = 0;
    }

    for(auto i: adj){
        for(auto j: i.second){
            int u = i.first;
            int v = j.first;
            int wt = j.second;

            dis[u][v] = wt;
        }
    }


    for(int helper = 0; helper < n; helper++){
        for(int src = 0; src < n; src++){
            for(int des = 0; des < n; des++){
                dis[src][des] = min(dis[src][des], dis[src][helper]  + dis[helper][des]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dis[i][j] << " ";
        }

        cout << endl;
    }
}



int main(){
    Graph G;
    G.addEdge(0,1,3,0);
    G.addEdge(1,0,2,0);
    G.addEdge(0,3,5,0);
    G.addEdge(3,2,2,0);
    G.addEdge(1,3,4,0);
    G.addEdge(2,1,1,0);

    G.printAdj();

    FloydWarshal(G.adj, 4);
}
