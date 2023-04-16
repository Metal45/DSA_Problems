#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int col, int row, int n){
    int i = row, j = col;
    while(i >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
    }

    i = row, j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }

        i--;
        j--;
    }

    i = row, j = col;
    while(j < n && i >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }

        i--;
        j++;
    }

    return true;
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

void solve(vector<vector<char>> &board, int row, int n){
    if(row >= n){
        printAns(board, n);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(board, col, row, n)){
            board[row][col] = 'Q';
            solve(board, row + 1, n);
            board[row][col] = '-';
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    solve(board, 0, n);
}