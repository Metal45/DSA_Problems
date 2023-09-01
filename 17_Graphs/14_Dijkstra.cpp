// It can not be applied on the graphs with negative weight and negative weight cycles 

// Dijkstra can be implemented using queue, priority_queue, set

// why does it work? 
// ?

// why not queue?
// using queue is the brute force apporach, that is going down every possible path and firuring out the shortest. Whereas you can
// be greedy and choose to go along the minimum path.


// why PQ or set?
// pq or set are used to fetch the next minimum distance node


// which one is better?
// you can not point out and say which is better as both of them have roughly the same complexity. but set can erase the current 
// irrelevant calls so it saves some iterations which heap can not but at the same time it takes logarithmic time to do so. So it depends
// upon the graph that which would be better for it. Heap or Set.


// TC of each with set, PQ
// set, PQ -> ElogV



// using set
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


// using set
void DijkstraUsingSet(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> &dis){
    set<pair<int, int>> nodes;
    nodes.insert({0, src});

    while(!nodes.empty()){
        auto front = *(nodes.begin());
        nodes.erase(nodes.begin());

        int nodeDis = front.first;
        int currNode = front.second;

        for(auto nbr : adj[currNode]){

            if(nbr.second + nodeDis < dis[nbr.first]){
                auto search = nodes.find({dis[nbr.first], nbr.first});
                if(search != nodes.end()){
                    nodes.erase(search);
                }
                dis[nbr.first] = nbr.second + nodeDis;
                nodes.insert({dis[nbr.first], nbr.first});
            }
        }
    }

    for(int i = 1; i < dis.size(); i++){
        cout << "Dis from " << src << " to " << i << " : " << dis[i] << endl; 
    }
}

// using priority queue
void DijkstraUsingPQ(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> &dis){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, 0});
    dis[0] = 0;

    while(!minHeap.empty()){
        auto p = minHeap.top();
        int node = p.first;
        int nodeDis = p.second;
        minHeap.pop();

        for(auto nbr : adj[node]){
            if(nodeDis + nbr.second < dis[nbr.first]){
                dis[nbr.first] = nodeDis + nbr.second;
                minHeap.push({dis[nbr.first], nbr.first});
            }
        }
    }

    for(int i = 1; i < dis.size(); i++){
        cout << "Dis from " << src << " to " << i << " : " << dis[i] << endl; 
    }
}

int main(){
    Graph G;
    G.addEdge(6,3,2,1);
    G.addEdge(6,1,14,1);
    G.addEdge(3,1,9,1);
    G.addEdge(3,2,10,1);
    G.addEdge(1,2,7,1);
    G.addEdge(2,4,15,1);
    G.addEdge(4,3,11,1);
    G.addEdge(6,5,9,1);
    G.addEdge(4,5,6,1);

    int n, src;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> dis(n + 1, INT_MAX);

    cout << "Enter src: ";
    cin >> src;

    dis[src] = 0;

    DijkstraUsingPQ(src, G.adj, dis);
    DijkstraUsingSet(src, G.adj, dis);
}

