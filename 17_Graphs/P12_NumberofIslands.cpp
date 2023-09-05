class Solution {
public:
    void mark(int i , int j, vector<vector<char>> &grid){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        // marking all the connected land to current land as visited

        // down
        mark(i - 1, j, grid);

        // up
        mark(i + 1, j, grid);

        // left
        mark(i , j - 1, grid);

        // right
        mark(i , j + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                // increasing the count of land if it is still unvisited 
                if(grid[i][j] == '1'){
                    count++;
                    mark(i, j, grid);
                }
            }   
        }

        return count;
    }
};