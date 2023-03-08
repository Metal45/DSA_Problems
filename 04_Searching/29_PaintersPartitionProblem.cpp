bool check(int arr[], int n, int k, long long mid){
    int c = 1;
    long long cost = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid){
            return false;
        }
        cost += arr[i];
        
        if(cost > mid){
            c++;
            cost = arr[i];
            if(c > k){
                return false;
            }
        }
    }
    
    return true;
}

long long minTime(int arr[], int n, int k)
{
    
    long long s = 0;
    long long e = 0;
    for(int i = 0; i < n; i++){
        e += arr[i];
    }
    long long ans = 0;
    while(s <= e){
        long long mid = s + (e - s)/2;
        if(check(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    
    return ans;
}