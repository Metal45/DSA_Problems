#include <bits/stdc++.h>
using namespace std;

// without using visited array

class Solution {
public:
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, -1, 0, 1};

    void dfs(int row, int col, vector<vector<char>>& board){
        board[row][col] = '#';
        int m = board.size();   
        int n = board[0].size();

        for(int i = 0; i < 4; i++){
            int newi = dirx[i] + row;
            int newj = diry[i] + col;

            if(newi < m && newi >= 0 && newj < n && newj >= 0 && board[newi][newj] == 'O'){
                dfs(newi, newj, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board);
            }
            if(board[m - 1][i] == 'O'){
                dfs(m - 1, i, board);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if(board[i][n - 1] == 'O'){
                dfs(i, n - 1, board);
            }
        } 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }       
    }
};

// with visited array

class Solution {
public:
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, -1, 0, 1};

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &visited){
        visited[row][col] = 1;
        int m = board.size();   // rows
        int n = board[0].size();

        for(int i = 0; i < 4; i++){
            int newi = dirx[i] + row;
            int newj = diry[i] + col;

            if(newi < m && newi >= 0 && newj < n && newj >= 0 && board[newi][newj] == 'O' && visited[newi][newj] != 1){
                dfs(newi, newj, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O' && visited[0][i] != 1){
                dfs(0, i, board, visited);
            }
            if(board[m - 1][i] == 'O' && !visited[m - 1][i]){
                dfs(m - 1, i, board, visited);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && visited[i][0] != 1){
                dfs(i, 0, board, visited);
            }
            if(board[i][n - 1] == 'O' && visited[i][n -1] != 1){
                dfs(i, n - 1, board, visited);
            }
        } 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && visited[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }       
    }
};