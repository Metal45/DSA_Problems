vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // Efficient Approach: TC O(N) SC O(1) -> The given array is sorted and we have to find a window of k elements such that they are closest to x, we take two pointers start and end now since we have to consider
    // the absoulte difference so if the difference of start and end with x is same you will consider start in the group of k.
    // Since the k <= n so we will contract the window length until it becomes equal to K and while contracting we will only take the closest elements. We will compare x - s and e - x
    // since we have to take absolute difference and e > s we are taking e - x not x - e, you can also take abs diff. if first diff is less that equal to second we will include s and 
    // exclude e and do the opposite if e diff is smaller. And eventually the size of the window will be reduced to K

    int s = 0, e = arr.size() - 1;
    while(e - s >= k){
        if(x - arr[s] > arr[e] - x){
            s++;
        }else{
            e--;
        }
    }

    return vector<int>(arr.begin() + s, arr.begin() + e + 1);
}


// Not wroking 2nd method

int closestIndex(vector<int> arr, int x){
        int s = 0, e = arr.size() - 1;
        int ans = e;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(arr[mid] >= x){
                ans = mid;
                e = mid - 1;
            }else if(x > arr[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int e = closestIndex(arr, x);
        int s = e - 1;

        while(k--){
            if(s < 0){
                e++;
            }else if(e >= arr.size()){
                s--;
            }else if(x - arr[s] > arr[e] - x){
                e++;
            }else{
                s--;
            }
        }

        return vector<int>(arr.begin() + s + 1, arr.end() + e);
    }