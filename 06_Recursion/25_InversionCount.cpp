#include <iostream>
using namespace std;

void inv(long long arr[], long long s, long long e, long long &count){
    long long mid = s + (e - s)/2;
    long long l1 = mid - s + 1;
    long long l2 = e - mid;
    long long *left = new long long[l1];
    long long *right = new long long[l2];
    
    long long k = s;
    for(int i = 0; i < l1; i++){
        left[i] = arr[k++];
    }
    
    for(int i = 0; i < l2; i++){
        right[i] = arr[k++];
    }
    
    int i = 0, j = 0;
    k = s;
    
    while(i < l1 && j < l2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            count += l1 - i;
            arr[k++] = right[j++];
        }
    }
    
    while(i < l1){
        arr[k++] = left[i++];
    }
    
    while(j < l2){
        arr[k++] = right[j++];
    }
}

void solve(long long arr[], long long s, long long e, long long &count){
    if(s < e){
        int long long mid = s + (e - s)/2;
        solve(arr, s, mid, count);
        solve(arr, mid + 1, e, count);
    
        inv(arr, s, e, count);
    }
}

long long inversionCount(long long arr[], long long N)
{
    long long count = 0;
    solve(arr, 0, N - 1, count);
    return count;
}

int main(){
    int n;
    cin >> n;
    long long *arr = new long long[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long count = inversionCount(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << count << endl;
}




// 2nd method wihtout reference variables

// long long int inv(long long int arr[], long long int s, long long int e){
//     long long int count = 0;
//     long long int mid = s + (e - s)/2;
//     long long int l1 = mid - s + 1;
//     long long int l2 = e - mid;
//     long long int *left = new long long int[l1];
//     long long int *right = new long long int[l2];
    
//     long long int k = s;
//     for(int i = 0; i < l1; i++){
//         left[i] = arr[k++];
//     }
    
//     for(int i = 0; i < l2; i++){
//         right[i] = arr[k++];
//     }
    
//     int i = 0, j = 0;
//     k = s;
    
//     while(i < l1 && j < l2){
//         if(left[i] <= right[j]){
//             arr[k++] = left[i++];
//         }else{
//             count += l1 - i;
//             arr[k++] = right[j++];
//         }
//     }
    
//     while(i < l1){
//         arr[k++] = left[i++];
//     }
    
//     while(j < l2){
//         arr[k++] = right[j++];
//     }
    
//     return count;
// }

// long long int solve(long long arr[], long long s, long long e){
//     long long int count = 0;
//     if(s < e){
//         int long long mid = s + (e - s)/2;
//         count += solve(arr, s, mid);
//         count += solve(arr, mid + 1, e);
    
//         count += inv(arr, s, e);
//     }
    
//     return count;
// }

// long long int inversionCount(long long arr[], long long N)
// {
//     return solve(arr, 0, N - 1);
// }