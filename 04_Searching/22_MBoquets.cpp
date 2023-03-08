bool check(vector<int> bloomDay, int mid, int m, int k){
    int total = 0, count = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= mid){
            count++;
            if(count == k){
                total++;
                count = 0;
            }
        }else{
            count = 0;
        }
    }
    if(total >= m){
        return true;
    }else{
        return false;
    }
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int s = 1, e = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(check(bloomDay, mid, m, k)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}