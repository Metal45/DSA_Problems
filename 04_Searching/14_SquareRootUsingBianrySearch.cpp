// Find the floor value of square root of a number using binary search
// It is a type of question in which ans is in the seach space 

// Approach -> TC O(LogN) SC O(1)
// Instead of going from 1 to n and doing square of every term you can do it using binary search select the search space between 0 and N/2 or N go to mid and check if mid is root 
// and return if it is if not check if and is smaller than the square if yes store it since you have to return the floor value and search in right for the larger answer
// else search in left

int mySqrt(int x) {
        int s = 0, e = x, ans = -1;

        while(s <= e){
            long long int mid = s + (e - s)/2;
            if(mid * mid  == x){
                return mid;
            }
            else if(mid * mid < x){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return ans;
    }