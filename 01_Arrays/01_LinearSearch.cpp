// TC -> O(N) SC O(1)
int search(int arr[], int N, int K) 
    { 
       for(int i = 0; i < N; i++){
           if(arr[i] == K){
               return i;
           }
       }
       
       return -1;
    }