#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int k, int board[][9], int i, int j){
    for(int col = 0; col < 9; col++){
        if(board[i][col] == k){
            return false;
        }
    }

    for(int row = 0; row < 9; row++){
        if(board[row][j] == k){
            return false;
        }
    }


    for(int l = 0; l < 9; l++){
        if(board[3*(i/3)][] == k){
            return false;
        } 
    }

    return true;
}

bool solve(int board[9][9], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                for(int k = 0; k < 9; k++){
                    if(isSafe(k, board, i, j)){
                        board[i][j] = k;
                        bool next = solve(board, n);
                        if(next){
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}  

int main(){
    int board[9][9] = {{4,5,0,0,0,0,0,0,0},
    {0,0,2,0,7,0,6,3,0}, 
    {0,0,0,0,0,0,0,2,8}, 
    {0,0,0,9,5,0,0,0,0},
    {8,8,6,0,0,0,2,0,0},
    {0,2,0,6,0,0,7,5,0},
    {0,0,0,0,0,8,4,7,6},
    {0,7,0,0,4,5,0,0,0},
    {0,0,8,0,0,9,0,0,0}};

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << "   ";
        }
        cout << endl << endl;
    }

    bool ans = solve(board, 9);
}