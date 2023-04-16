int *findTwoElement(int *arr, int n) {
    int repeated = 0, missing = 0;
    
    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0){
            repeated = abs(arr[i]);
            continue;
        }
        
        arr[index] *= -1;
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            missing = i + 1;
            break;
        }
    }
    
    int *ans = new int[2];
    ans[0] = repeated;
    ans[1] = missing;
    return ans;
}