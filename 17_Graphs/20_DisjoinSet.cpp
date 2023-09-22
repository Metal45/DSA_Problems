#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;

    public:     
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionbyRank(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(v != u){
            if(rank[u] < rank[v]){
                parent[u] = v;
            }else if(rank[v] < rank[u]){
                parent[v] = u;
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    void unionbySize(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(u != v){
            if(size[u] < size[v]){
                parent[u] = v;
                size[v] += size[u];
            }else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }
};

