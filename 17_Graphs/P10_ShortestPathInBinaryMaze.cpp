// using DFS 
// This throws TLE as you will explore every possible path to the destination and find the shortest among them

class Solution {
public:
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

    void dfs(int i, int j, int n, vector<vector<int>> &grid, int &minLen, int len){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 0){
            return;
        }

        
        if(i == n - 1 && j == n - 1){
            minLen = min(minLen, len);
            return ;
        }

        grid[i][j] = 1;

        for(int k = 0; k < 8; k++){
            dfs(i + dir[k][0], j + dir[k][1], n, grid, minLen, len + 1);
        }

        grid[i][j] = 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
            return -1;
        }
        
        int minLen = INT_MAX, len = 1;
        dfs(0, 0, n, grid, minLen, len);

        return minLen == INT_MAX ? -1 : minLen; 
    }
};



// using BFS
// Approach -> As we know BFS explores nodes level wise so whenever we encounter the destination node that will be on the shortest distance from the source node
// until then just explore all the neighbours one by one and increase the path by one
class Solution {
public:
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<pair<int,int>, int>> pending;
        pending.push({{0,0}, 1});
        grid[0][0] = -1;

        while(!pending.empty()){
            auto p = pending.front();
            int x = p.first.first;
            int y = p.first.second;
            int path = p.second;

            if(x == n - 1 && y == n - 1){
                return path;
            }

            pending.pop();

            for(int k = 0; k < 8; k++){
                int i = x + dir[k][0];
                int j = y + dir[k][1];
                if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0){
                    grid[i][j] = -1;
                    pending.push({{i,j}, path+1});
                }
            }
        }

        return -1;
    }
};