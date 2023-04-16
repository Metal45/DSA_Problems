#include <iostream>
#include <vector>
using namespace std;

void WavePrint(vector<vector<int>> A, int n){
    /// int n = A[0].size();
    for(int j = 0; j < n; j++){
        if(j % 2 != 0){
            for(int i = n - 1; i >= 0; i--){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }else{
            for(int i = 0; i < n; i++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    vector<vector<int>> A{
        {1, 9, 4, 10}, 
        {3, 6, 90, 11}, 
        {2, 30, 85, 72}, 
        {6, 31, 99, 15}
    };
    WavePrint(A, 4);
}