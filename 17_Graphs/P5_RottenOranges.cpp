#include <bits/stdc++.h>
using namespace std;

// BFS 
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> pending;
    int row = grid.size(), col = grid[0].size();
    int freshOranges = 0, minutesElapsed = -1;

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 2){
                pending.push({i, j});
            }else if(grid[i][j] == 1){
                freshOranges++;
            }
        }
    }


    while(!pending.empty()){
        int size = pending.size();

        for(int k = 0; k < size; k++){
            int currRow = pending.front().first;
            int currCol = pending.front().second;
            pending.pop();

            for(int i = 0; i < 4; i++){
                int newRow = currRow + dir[i][0];
                int newCol = currCol + dir[i][1];

                if(newRow < row && newRow >= 0 && newCol < col && newCol >= 0 && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    freshOranges--;
                    pending.push({newRow, newCol});
                }
            }
        }

        minutesElapsed++;
    }  

    // oranges still left
    if(freshOranges > 0){
        return -1;
    }

    // if time == -1 (the grid was empty -> no rotten no fresh for which answer would be 0)
    return minutesElapsed == -1 ? 0 : minutesElapsed;
