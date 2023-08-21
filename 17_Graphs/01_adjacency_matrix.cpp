#include <bits/stdc++.h>
using namespace std;

// creating adjacency matrix for the graph

int main(){

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    // initializing adj mat
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // filling the adj mat
    for(int i = 0; i < e; i++){
        int u, v;

        // marking the edge from u to v as 1
        cin >> u >> v;
        adj[u][v] = 1;
    }

    // printing the adj matrix

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}