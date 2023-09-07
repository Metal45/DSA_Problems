// What does it state?
// How does it work?
// Why BellmanFord?

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

void BellmanFord(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> dis){
    int n = adj.size();
    dis[src] = 0;

    // calculating the shortest path from src to all nodes
    for(int i = 0; i < n -1; i++){
        for(auto node : adj){
            int u = node.first;
            for(auto nbr : node.second){
                int v = nbr.first;
                int wt = nbr.second;
                if(dis[u] != INT_MAX && dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt; 
                }
            }
        }
    }

    // checking for the negative cycles
    for(auto node : adj){
            int u = node.first;
            for(auto nbr : node.second){
                int v = nbr.first;
                int wt = nbr.second;
                if(dis[u] != INT_MAX && dis[u] + wt < dis[v]){
                    cout << "There exists a negative cycle" << endl;
                    return;
                }
            }
        }

    for(int i = 1; i < dis.size(); i++){
        cout << "Dis from " << src << " to " << i << " : " << dis[i] << endl; 
    }
    
    cout << endl;
}

void DijkstraUsingPQ(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> dist){
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(adj.size() + 1, false);
    pq.push({0,src});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        visited[node] = true;
        pq.pop();
        
        for(auto x:adj[node]){
            int adj_node = x.first;
            int wt = x.second;
            
            if(!visited[adj_node] && dist[adj_node] > dis+wt){
                dist[adj_node] = dis+wt;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }

    for(int i = 1; i < dist.size(); i++){
        cout << "Dis from " << src << " to " << i << " : " << dist[i] << endl; 
    }

    cout << endl;
}


int main(){
    Graph G;
    G.addEdge(1,2,4,0);
    G.addEdge(2,3,-4,0);
    G.addEdge(1,3,1,0);

    int n, src;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> dis(n + 1, INT_MAX);

    cout << "Enter src: ";
    cin >> src;

    cout << "According to Dijkstra: ";
    DijkstraUsingPQ(src, G.adj, dis);

    cout << "According to Bellman Ford: ";
    BellmanFord(src, G.adj, dis);
}
