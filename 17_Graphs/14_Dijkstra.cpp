// What does it state
// Dijkstra Algo is used for finding the shortest parth between the source to every other vertex in the graph, provided the graph does not contain 
// negative edge weights and negative cycles. 

// Working of Dijkstra
// Dijkstra can be implemented using queue, priority_queue, set
// Dijsktra starts from the soruce node marking its dis[S] = 0 and then visits all the neigbour nodes and if the dis to the neighbour node is less than
// the current dis of that node then it gets updated and pushed into the data structure beinng used this process is repeated unitl all the nodes are visited (if using a visited array)
// or the data structure is not empty.
// Conventionally it also maintains a visited array and only visit a node once as the it is already going thorugh the shortest path but you can also 
// do it without the visited array as one node (if all the edge weights are positive) only gets pushed in the heap or set once (you can check). But it is good
// to use visited array else you algo will also run for negative weights and cycles.

// Why not queue?
// using queue is the brute force apporach, that is going down every possible path and firuring out the shortest. Whereas you can
// be greedy and choose to go along the minimum path.

// Why PQ or set?
// pq or set are used to fetch the next minimum distance node

// Which is better Set or Priority Queue?
// you can not point out and say which is better as both of them have roughly the same complexity. but set can erase the current 
// irrelevant calls so it saves some iterations which heap can not but at the same time it takes logarithmic time to do so. So it depends
// upon the graph that which would be better for it. Heap or Set.

// Derivation of Time Complexity of Dijkstras Algorithm 
// set, PQ -> ElogV

// WHERE DOES IT FAIL? -> It can not be applied on the graphs with negative weight and negative weight cycles 
// If there exists a negative cycle you will get caught in an infinite loop as after each cycle there would be a shorter path available and
// you will never get out of the priority queue or set

// Why does it fail for Negative Edges?
// In the algo whenever you take the element out of queue or set it does not enter the data structure again becuase the shortest path to that node from 
// the source has already been updated but this is only true if all the edge weights in the graph are positive as whenever you will try to revisit this 
// particular node it will always be thorugh a larger path as something will be added to the already existing shorter path so it will never be pushed again
// That is why we does not need to use a visiting array but if we use a visiting array.
// Now for negative edge weights even after pulling the node put of the data structure we can encounter some negative edge weight that will decrease the current 
// shortest path and will ask to push it back again in data structure but we will not do so as it is against the algorithm. So to see the Dijkstra failing 
// for negative edge weights we will have to use a visiting array else it will give the correct answer for neg weights also.

// Why does it fail for negative cycles?
// In the negative cycle next after every loop their will be a shorter distance available for the nodes which will not let you come out of infinite loop
// as the data structure will never be empty. So it will give TLE.


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


// USING PRIORITY QUEUE
void DijkstraUsingSet(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> dis){
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


// USING PRIORITY QUEUE 
void DijkstraUsingPQ(int src, unordered_map<int, list<pair<int, int>>> &adj, vector<int> dist){
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto x:adj[node]){
            int adj_node = x.first;
            int wt = x.second;
            
            if(dist[adj_node] > dis+wt){
                dist[adj_node] = dis+wt;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }

    for(int i = 1; i < dist.size(); i++){
        cout << "Dis from " << src << " to " << i << " : " << dist[i] << endl; 
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

