int mod = 1e9 + 7;
void solve(int arr[], int i, int sum, int target, int n, int &count){
    if(i >= n){
        if(sum == target){
            count++;
        }
        return;
    }
    
    if(sum + arr[i] <= target){
        solve(arr, i + 1, sum + arr[i], target, n, count);
    }

    solve(arr, i + 1, sum, target, n, count);
}
    
int perfectSum(int arr[], int n, int sum)
{
    int count = 0;
    solve(arr, 0, 0, sum, n, count);
    return count % mod;
}