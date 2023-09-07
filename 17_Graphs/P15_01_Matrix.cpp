#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dis(n , vector<int> (m, 0));
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<pair<int,int>, int>> pending;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    pending.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
 
        while(!pending.empty()){
            int i = pending.front().first.first;
            int j = pending.front().first.second;
            int steps = pending.front().second;
            pending.pop();
            dis[i][j] = steps;

            for(int k = 0; k < 4; k++){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < n && y < m && x >= 0 && y >= 0 && !visited[x][y])
                {
                    pending.push({{x, y}, steps + 1});
                    visited[x][y] = true;
                }
            }
        }

        return dis;
    }
};

