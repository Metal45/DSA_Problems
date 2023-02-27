// Find the floor value of division of two numbers using binary search m / n



// Brute Force: TC -> O(N) SC O(1) Take search space from 1 to M and multiply each number by n and check if it is less than or equal to m

// Efficient Approach -> TC O(LogN) SC O(1) Binary Search Take the same search space but now this time instead of checking from start we check if mid*n == m return,  mid*n < m store it and search in right
// as we have to find the next larger floor vlaue and if > m search in left side.

long long divide(long long dividend, long long divisor) 
{
    int s = 0;
    int e = abs(dividend);
    int ans = -1;
    
    while(s <= e){
        int mid = s + (e - s)/2;
        
        if(mid*abs(divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        
        if(mid*abs(divisor) < abs(dividend)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    
    if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)){
        return ans;
    }else{
        return -ans;
    }
}