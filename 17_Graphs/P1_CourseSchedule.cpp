#include <bits/stdc++.h>
using namespace std;

// Approach -> 
// You can only complete every course agar jo course dependent hai kisi a inpendent course pe and uska dependent course vapis a pe depend kare
// like a -> b and b -> c then c -> a aise b karne ke liye a ko karna hai c ke liye b and a ke liye c 
// you are caught in a loop, therefore if the graph is cyclic then you won't be able to complete all courses

// you can check with 2 approaches if the directed graph is cyclic -> i. ) BFS (Topological Sort)
//                                                                   ii. ) DFS 

void buildadj(vector<vector<int>>& prerequisites, unordered_map<int, vector<int>> &adj, vector<int> &inDegree){
    for(int i = 0; i < prerequisites.size(); i++){
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u].push_back(v);
        inDegree[v]++;
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<int> inDegree(numCourses, 0);

    buildadj(prerequisites, adj, inDegree);

    queue<int> pending;
    int count = 0;

    for(int i = 0; i < numCourses; i++){
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

    return count == numCourses;
}
