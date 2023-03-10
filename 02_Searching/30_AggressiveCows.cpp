bool check(vector<int> stalls, int k, int n, int mid){
    int count  = 1, curr = stalls[0];
    
    for(int i = 1; i < n; i++){
        if(stalls[i] - curr >= mid){
            count++;
            curr = stalls[i];
            
        }
        
        if(count == k){
            return true;
        }
    }
    
    return false;    
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    
    int s = 1, e = stalls[n - 1] - stalls[0], ans = -1;
    while(s <= e){
        int mid = s + (e - s)/2;
        
        if(check(stalls, k, n, mid)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        
    }
    
    return ans;
}