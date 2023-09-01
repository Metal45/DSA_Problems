class Solution {
public:
int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>>& roads) {
    unordered_map<int, list<pair<int, int>>> adj;
    for(auto road : roads){
        int u = road[0];
        int v = road[1];
        int w = road[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dis(n, 1e15);
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
    minHeap.push({0, 0});
    ways[0] = 1;
    dis[0] = 0;

    while(!minHeap.empty()){
        auto p = minHeap.top();
        int node = p.second;
        long long nodeDis = p.first;
        minHeap.pop();

        for(auto nbr : adj[node]){
            if(nodeDis + nbr.second < dis[nbr.first]){
                ways[nbr.first] = ways[node];
                dis[nbr.first] = nodeDis + nbr.second;
                minHeap.push({dis[nbr.first], nbr.first});
            }else if(nodeDis + nbr.second == dis[nbr.first]){
                ways[nbr.first] = (ways[nbr.first] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1] % mod;
}
};