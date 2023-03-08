bool check(int A[], int N, int M, int mid){
        int c = 1;
        int pageSum = 0;
        
        for(int i = 0; i < N; i++){
            if(A[i] > mid){
                return false;
            }
            
            pageSum += A[i];
            
            if(pageSum > mid){
                c++;
                pageSum = A[i];
                if(c > M){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M > N){
            return -1;
        }
        
        int s = 0, e = accumulate(A, A + N, 0);
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(check(A, N, M, mid)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return ans;
    }