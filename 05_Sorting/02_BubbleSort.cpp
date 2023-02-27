#include <iostream>
using namespace std;

// In Bubble sort (sinking sort) we place the largest element at the end by swapping
// In first round we do n - 1 comparisions and then n - 2 and n - 3 upto ... 1 
// Time Complexity -> n - 1 + n - 2 + n - 3 + ...... + 1 
// TC -> O(N2) SC -> O(1)

// We can optimise this algorithm by placing a flag inside the loop indicating wheter swapping has been done in the last round or not if 
// no swapping has been done in the last round then the array is already sorted and there is no need of further comparisions which will improve the time complexity

void BubbleSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++){

            if(arr[j] > arr[j + 1]){
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if(swapped == false){
            break;
        }
    }

}

int main(){
    int n;
    cin >> n;
    int *arr = new int[10];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Input array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}