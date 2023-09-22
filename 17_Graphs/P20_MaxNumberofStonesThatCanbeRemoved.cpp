// return maximum number of that be removed having same column or row

// how is the answer n - components (n = number of stones)
// if there is a component with n nodes you can at max remove n - 1 as the last stone will not have anyone left to have a common row or column 
// n = c1 + c2 + c3 + ........   n1 -> number of stones that can be removed from c1 that is n1 = c1 - 1;
// n = n1 + 1 + n2 + 1 + n3 + 1 ........
// n = (n1 + n2 + n3 + .... ) + (1 + 1 + 1 .....) (1 is added number of component times)
// n = ans + c * 1 
// ans = n - c


// So the problem is now reduced to finding the number of components/ groups with stones of either same row and column

// Approach 1 -> DFS

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // checking how many stones are connected to the current Stone
    void connected(vector<vector<int>> &stones, int currStone, vector<bool> &visited){
        visited[currStone] = true;

        for(int nbrStone = 0; nbrStone < stones.size(); nbrStone++){
            if(!visited[nbrStone]){
                // checking if the nbr stone have a row or column common with the currStone
                if(stones[currStone][0] == stones[nbrStone][0] || stones[currStone][1] == stones[nbrStone][1]){
                    connected(stones, nbrStone, visited);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), components = 0;
        vector<bool> visited(n, false);

        // calculating number of components
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                connected(stones, i, visited);
            }
        }

        return n - components;
    }
};




// Approach 2 -> Using Disjoint Set

// implementing disjoint set by rank and path compression
class Disjoint{
    public:
    vector<int> rank, parent;

    Disjoint(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(u != v){
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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = -1, maxCol = -1;

        // calculating number of rows and columns
        for(int i = 0; i < stones.size(); i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        Disjoint ds(maxRow + maxCol + 2);
        map<int, int> stoneNodes;

        // grouping the stones into components -> such that the stones with either the same column or row will be grouped
        for(auto it : stones){
            int u = it[0];
            int v = it[1] + maxRow + 1;
            u = ds.findParent(u);
            v = ds.findParent(v);
            ds.unionSet(u, v);
            stoneNodes[u]++;
            stoneNodes[v]++;
        }

        // finding the number of components -> 
        // 1. the number of components will be equal to the ultimate parent nodes
        // 2. ultimate parent nodes are those which are the parent of themselves
        // 3. in order to find the number of components u need to find the ultimate parent nodes
        // 4. store the rows and columns of stones in a map and then find the parent of the row and column number
        int c = 0;
        for(auto it : stoneNodes){
            if(ds.findParent(it.first) == it.first){
                c++;
            }
        }

        // set<int> st;
        // for(auto it : stones){
        //     int u = it[0];
        //     int v = it[1] + maxRow + 1;
        //     st.insert(ds.findParent(u));
        //     st.insert(ds.findParent(v));
        // }
        // int c = st.size();
       
        int n = stones.size();
        return n - c;
    }
};