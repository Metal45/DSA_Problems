
// THIS IS DFS -> 
// write approach ?
// how from bfs?
// why not directly return dfs ->
// if(!dfs(nbr, !currColor, graph, color)){
//                     return false;
//                 }

class Solution {
public:
  
    bool dfs(int src, int currColor, vector<vector<int>>& graph, vector<int> &color){
        color[src] = currColor;

        for(auto nbr : graph[src]){
            if(color[nbr]  == -1){
                // why not directly return dfs
                if(!dfs(nbr, !currColor, graph, color)){
                    return false;
                }
            }else if(color[nbr] == currColor) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(i,0,graph,color)){
                    return false;
                }
            }
        }

        return true;
    }
};