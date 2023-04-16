void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int size = m + n;
    int gap = (size/2) + (size % 2);
    
    while(gap > 0){
        int i = 0, j = gap;
        while(j < size){
            // comparing elements in the first array
            if(j < n && arr1[i] > arr1[j]){
                swap(arr1[i], arr1[j]);
            }
            
            // comaring elements in both arrays
            else if(i < n && j >= n && arr1[i] > arr2[j - n]){
                swap(arr1[i], arr2[j - n]);
            }
            
            // comparing elements in the second array
            else if(i >= n && j >= n && arr2[i - n] > arr2[j - n]){
                swap(arr2[i - n], arr2[j - n]);
            }
            
            i++;
            j++;
        }
        
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
} 