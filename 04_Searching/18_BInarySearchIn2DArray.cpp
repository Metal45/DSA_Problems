// Search For An element in A 2D array using binary search 


// Approach TC O(LogN) SC O(1) -> Binary search in a matrix is similar to binary search in a 1d array we just have to find out the coulmn and row index from mid and imagine it as 1d array

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int s = 0;
    int e = n*m - 1;
    

    while(s <= e){
        int mid = s + (e - s) / 2;
        int i = mid / m;
        int j = mid % m;

        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return false;
}