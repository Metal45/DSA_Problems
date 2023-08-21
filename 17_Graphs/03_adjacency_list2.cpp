// adjacency list for the weighted graphs

#include <bits/stdc++.h>
using namespace std;

class graph{
    public:

    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, bool direction){
        adj[u].push_back({v, weight});

        if(!direction){
            adj[v].push_back({u, weight});
        }
    }

    void printAdj(){
        for(auto i : adj){
            cout << i.first << "-> "; 

            for(auto j : i.second){
                cout << "(" << j.first << ", " << j.second << ")  ";
            }

            cout << endl;
        }
    }
};

int main(){
    graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,8,1);
    g.addEdge(0,2,6,1);
    g.printAdj();
}