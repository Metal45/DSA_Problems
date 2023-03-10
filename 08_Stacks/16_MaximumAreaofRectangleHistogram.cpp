
// Logic - The area of rectangle can be maximised by my maximising the width as the length is constant so for each height you will find how much can you extent it left and rigth and
// then you will find the area 




// Optimised solution TC , SC O(N )- using stack or vector finding the next smaller elements from right and left for each element in the array before hand in O(N) time and O(N) space then iterate over  
// array and calculate the max width and area in O(N) space and time 

// using Stack






// using vector
int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(n == 0){
            return 0;
        }

        vector<int> left(n);
        left[0] = -1;
        for(int i = 1; i < n; i++){
            int prev = i - 1;
            while(prev >= 0 && heights[prev] >= heights[i]){
                prev = left[prev];
            }
            left[i] = prev;
        }

        vector<int> right(n);
        right[n - 1] = n;

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



//Brute Force  Approach -> iterate over the array and find the next smaller height for in both left and right direction and that will be your maximum width and the maximum area of rectangke for that height
// This Approach will give TLE, TC O(N2) SC O(1);
        int n = heights.size();
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            int curr = heights[i];
            int lwidth = 0, rwidth = 0, j = i - 1; 
            while(j >= 0){
                if(heights[j] >= curr){
                    lwidth++;
                }else{
                    break;
                }
                j--;
            }

            j = i + 1;

            while(j < n){
                if(heights[j] >= curr){
                    rwidth++;
                }else{
                    break;
                }
                j++;
            }

            int newArea = curr * (lwidth + rwidth + 1);
            maxArea = max(maxArea, newArea);
        }
        return maxArea;