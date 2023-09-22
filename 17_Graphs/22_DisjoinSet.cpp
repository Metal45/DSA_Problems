// A disjoint-set data structure is defined as one that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.

// A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

// Find:(findParent) Determine which subset a particular element is in. This can determine if two elements are in the same subset.
// Union (unionbyRank/unionbySize): Join two subsets into a single subset. Here first we have to check if the two subsets belong to the same set. If not, then we cannot perform union. 


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

