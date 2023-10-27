#include <iostream>
using namespace std;


// do more of it -> pivot with first as pivot, mid, last, randomised, time complexity and else
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int rightIndex = s + count;

    swap(arr[s], arr[rightIndex]);

    int i = s, j = e;
    while(i < rightIndex && j > rightIndex){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < rightIndex && j > rightIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return rightIndex;
}

int partition2(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int rightIndex = s + count;

    swap(arr[s], arr[rightIndex]);

    int i = s, j = e;
    while(i < rightIndex && j > rightIndex){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < rightIndex && j > rightIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return rightIndex;
}


void quickSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }

    int PivotIndex = partition(arr, s, e);

    quickSort(arr, s, PivotIndex - 1);
    quickSort(arr, PivotIndex + 1, e);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n -1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}