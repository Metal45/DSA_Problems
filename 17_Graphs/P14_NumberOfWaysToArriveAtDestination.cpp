// shortest path with K nodes Or shortest path with K stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }

        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
                priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({0, {0, src}});
        while(!minHeap.empty()){
            auto p = minHeap.top();
            int stop = p.first;
            int dist = p.second.first;
            int node = p.second.second;
            minHeap.pop();

            if(stop == k && node == dst){
                break;
            }

            if(stop > k){
                continue;
            }

            for(auto nbr : adj[node]){
                if(nbr.second + dist < dis[nbr.first]){
                    dis[nbr.first] = nbr.second + dist;
                    minHeap.push({stop + 1, {dis[nbr.first], nbr.first}});
                }

            }
        }

        if(dis[dst]==INT_MAX)
        return -1;
        return dis[dst];
    }
};