#include <bits/stdc++.h>
using namespace std;

class solution {
   public:
   int spanningTree(int V, vector<vector<int>> adj[])
    {
        int mst = 0;
        vector<bool> visited(V, false);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        
        while(!minHeap.empty()){
            auto p = minHeap.top();
            minHeap.pop();
            
            int wt = p.first;
            int u = p.second;
            
            if(visited[u] == true){
                continue;
            }
            
            visited[u] = true;
            mst += wt;
            
            for(auto i : adj[u]){
                int v = i[0];
                int dis = i[1];
                
                
                if(!visited[v]){
                    minHeap.push({dis, v});
                }
            }
        }
        
        return mst;
    }
};