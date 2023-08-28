#include <bits/stdc++.h>
using namespace std;

// DFS Solution
void removeLand(int currRow, int currCol, vector<vector<int>>& grid, int dir[][2]){
    grid[currRow][currCol] = 0;

    for(int i = 0; i < 4; i++){
        int newRow = currRow + dir[i][0];
        int newCol = currCol + dir[i][1];
        if(newRow < grid.size() && newRow >= 0 && newCol < grid[0].size() && newCol >= 0 && grid[newRow][newCol] == 1){
            removeLand(newRow, newCol, grid, dir);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1){
                if(grid[i][j] == 1){
                    removeLand(i, j, grid, dir);
                }
            }
        }
    }

    int landLeft = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
                landLeft++;
            }
        }
    }

    return landLeft;
}


// BFS Solution
int numEnclaves(vector<vector<int>>& grid) {
    int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> pending;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1){
                if(grid[i][j] == 1){
                    pending.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
    }


    while(!pending.empty()){
        auto p = pending.front();
        pending.pop();

        for(int i = 0; i < 4; i++){
            int newRow = p.first + dir[i][0];
            int newCol = p.second + dir[i][1];
            if(newRow < grid.size() && newRow >= 0 && newCol < grid[0].size() && newCol >= 0 && grid[newRow][newCol] == 1){
                pending.push({newRow, newCol});
                grid[newRow][newCol] = 0;
            }
        }
    } 

    int landLeft = 0;
    
    for(int i = 1; i < grid.size() - 1; i++){
        for(int j = 1; j < grid[i].size() - 1; j++){
            if(grid[i][j] == 1){
                landLeft++;
            }
        }
    }

    return landLeft;
}