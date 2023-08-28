#include <bits/stdc++.h>
using namespace std;


// BFS Solution
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans = image;
    int row = image.size();
    int col = image[0].size();

    queue<pair<int, int>> pending;
    pending.push({sr, sc});
    ans[sr][sc] = color;


    int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int init = image[sr][sc];


    while(!pending.empty()){
        auto p = pending.front();
        int currRow = p.first;
        int currCol = p.second;
        pending.pop();

        for(int i = 0; i < 4; i++){
            int newRow = currRow + dir[i][0];
            int newCol = currCol + dir[i][1];

            if(newRow < row && newRow >= 0 && newCol < col && newCol >= 0 && image[newRow][newCol] == init && ans[newRow][newCol] != color){
                ans[newRow][newCol] = color;
                pending.push({newRow, newCol});
            }
        }
    }

    return ans;
}


// DFS Solution

void dfs(vector<vector<int>> &ans, int sr, int sc, int init, int color, int dir[][2]){
    ans[sr][sc] = color;
    for(int i = 0; i < 4; i++){
        int newSr = sr + dir[i][0];
        int newSc = sc + dir[i][1];

        if(newSr < ans.size() && newSr >= 0 && newSc < ans[0].size() && newSc >= 0 && ans[newSr][newSc] == init && ans[newSr][newSc] != color){
            dfs(ans, newSr, newSc, init, color, dir);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans = image;
    int init = image[sr][sc];
    int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    dfs(ans, sr, sc, init, color, dir);
    return ans;
}