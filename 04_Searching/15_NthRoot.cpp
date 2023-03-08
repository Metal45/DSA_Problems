// Find the nth root of M

// Brute force -> Linear Searh O(N) you can start from 1 and check if the number is nth root of m if yes return it

// Efficient Approach -> Binary Search TC O(LogN) It is similar to finding square root of the number only change is you have to look for nth power instead of squrare

int NthRoot(int n, int m)
	{
	    // Code here.
	    int s = 0, e = m;
	    while(s <= e){
	        int mid =  s + (e - s)/2;
	        
	        if(pow(mid, n) == m){
	            return mid;
	        }
	        if(pow(mid, n) > m){
	            e = mid - 1;
	        }else{
	            s = mid + 1;
	        }
	    }
	    return -1;
	}  