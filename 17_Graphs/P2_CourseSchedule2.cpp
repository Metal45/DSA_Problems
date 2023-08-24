#include <bits/stdc++.h>
using namespace std;

// This is the next problem of course schedule, if you can complete all the courses return the order in which you must approach the courses
// Approach -> Just return the topological sort if it exists else return the emptya array

void buildadj(vector<vector<int>>& prerequisites, unordered_map<int, vector<int>> &adj, vector<int> &inDegree){
    for(int i = 0; i < prerequisites.size(); i++){
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u].push_back(v);
        inDegree[v]++;
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<int> inDegree(numCourses, 0);
    buildadj(prerequisites, adj, inDegree);

    queue<int> pending;
    vector<int> ans;
    int count = 0;

    for(int i = 0; i < numCourses; i++){
        if(inDegree[i] == 0){
            pending.push(i);
        }
    }

    while(!pending.empty()){
        int front = pending.front();
        pending.pop();
        ans.push_back(front);

        for(auto nbr : adj[front]){
            inDegree[nbr]--;
            if(inDegree[nbr] == 0){
                pending.push(nbr);
            }
        }
    }

    if(ans.size() == numCourses){
        return ans;
    }else{
        return {};
    }
}