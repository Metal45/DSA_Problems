
// TC -> O(N) SC O(1)
void swapAlternate(int *arr, int size)
{
    int i=0;
    while(i<(size-1)){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        i=i+2;
    }
}