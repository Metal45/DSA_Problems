#include <bits/stdc++.h>
using namespace std;

// Approach -> 
// using topological sort 
// if the length of the topo sort is euqal to the number of vertices it shows that there exists a valid topo sort 
// if there exists a valid top then the graph is acyclic else the graph contains cycles 

bool isCyclic(int V, vector<int> adj[]) {
    queue<int> pending;
    vector<int> inDegree(V, 0);
    int count = 0;


    for(int i = 0; i < V; i++){
        
        for(auto nbr : adj[i]){
            inDegree[nbr]++;
        }
        
    }


    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0){
            pending.push(i);
        }
    }

    while(!pending.empty()){
        int front = pending.front();
        pending.pop();
        count++;
        
        for(auto nbr : adj[front]){
            inDegree[nbr]--;
            if(inDegree[nbr] == 0){
                pending.push(nbr);
            }
        }
    }

    

    if(count != V) {
        return true;
    }else{
        return false;
    }
}