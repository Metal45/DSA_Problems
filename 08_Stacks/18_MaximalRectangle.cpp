    // Approach -> TC O(M*N) SC O(N) 
    // We have to find out the area of the largest rectangle formed by 1 in the given matrix approach is to breakdown 
    // it into the sub probelms of histogram and look each row as a histogram and find out the max area of that row
    // and move forward to the next row and add the elements of the uppper row to the current, except 0 do the same for all
    // rows
    
    
    // Finding the maximum area of rectangle in the given row
    int maxAreaofRectangle(int heights[], int n)
    {
        int *left = new int[n];
        int *right = new int[n];
        
        left[0] = -1;
        right[n - 1] = n;
        
        for(int i = 1; i < n; i++){
            int prev = i - 1;
            while(prev >= 0 && heights[prev] >= heights[i]){
                prev = left[prev];
            }
            left[i] = prev;
        }
        
        
        for(int i = n - 2; i >= 0; i--){
            int prev = i + 1;
            while(prev < n && heights[prev] >= heights[i]){
                prev = right[prev];
            }
            right[i] = prev;
        }
        
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            int curr = heights[i];
            int width = right[i] - left[i] - 1;
            int newArea = curr * width;
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
    
    
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int maxArea = maxAreaofRectangle(M[0], m);
        
        // Merging the current row with upper rows    
        for(int i = 1; i < n; i++){
        
            for(int j = 0; j < m; j++){
        
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                
            }
            // finding the area of rectangle for the merged row and comprae it with the maxArea        
            maxArea = max(maxArea, maxAreaofRectangle(M[i], m));
        
        }

        return maxArea;
    }