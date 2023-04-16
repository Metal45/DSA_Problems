#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> UpDiagheck;
unordered_map<int, bool> LowDiagCheck;


bool isSafe(vector<vector<char>> &board, int col, int row, int n){

    if(rowCheck[row]){
        return false;
    }

    if(UpDiagheck[n - 1 + col - row]){
        return false;
    }

    if(LowDiagCheck[row + col]){
        return false;
    }

    return true;
    // int i = row, j = col;
    // while(j >= 0){
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    // }

    // i = row, j = col;
    // while(i >= 0 && j >= 0){
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }

    //     i--;
    //     j--;
    // }

    // i = row, j = col;
    // while(i < n && j >= 0){
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }

    //     i++;
    //     j--;
    // }

    // return true;
}

void printAns(vector<vector<char>> &board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void solve(vector<vector<char>> &board, int col, int n){
    if(col >= n){
        printAns(board, n);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(board, col, row, n)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            UpDiagheck[n - 1 + col - row] = true;
            LowDiagCheck[row + col] = true;
            solve(board, col + 1, n);
            board[row][col] = '-';
            rowCheck[row] = false;
            UpDiagheck[n - 1 + col - row] = false;
            LowDiagCheck[row + col] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    solve(board, 0, n);
}


// Optimised Code using maps isSafe in O(1)

    map<int, bool> rowcheck, UpDiagCheck, LowDiagCheck;

    bool isSafe(int row, int col, vector<string> &board, int n){
        if(rowcheck[row] || UpDiagCheck[n - 1 + col - row] || LowDiagCheck[row + col]){
            return false;
        }

        return true;
    }

    void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans){
        if(col >= n){
            ans.push_back(board);
            return ;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                rowcheck[row] = true;
                UpDiagCheck[n - 1 + col - row]= true; 
                LowDiagCheck[row + col] = true;
                solve(board, col + 1, n, ans);
                board[row][col] = '.';
                rowcheck[row] = false;
                UpDiagCheck[n - 1 + col - row] = false; 
                LowDiagCheck[row + col] = false;                
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> ans;
        solve(board, 0, n, ans);
        return ans;
    }