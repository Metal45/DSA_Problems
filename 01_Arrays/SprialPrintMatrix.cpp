vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> ans;
    int total_elements = m*n;
    int startRow = 0, startCol = 0, endRow = m - 1, endCol = n - 1;
    int count = 0;
    
    while(count < total_elements){
        // Printing The First Row
        for(int i = startCol; i <= endCol && count < total_elements; i++){
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;

        // Printing The End Col
        for(int i = startRow; i <= endRow && count < total_elements; i++){
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;
        
        // Printing The Last Row
        for(int i = endCol; i >= startCol && count < total_elements; i--){
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        // Printing The First Col
        for(int i = endRow; i >= startRow && count < total_elements; i--){
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }

    return ans;
}