vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    set<int> temp;
    while(i < n1 && j < n2 && k < n3){
        
        if(A[i] == B[j] && B[j] == C[k]){
            temp.insert(A[i]);
            i++, j++, k++;
        }
        else if(A[i] < B[j]){
            i++;
        }
        else if(B[j] < C[k]){
            j++;
        }
        else{
            k++;
        }
    }
    
    for(auto i : temp){
        ans.push_back(i);
    }
    
    return ans;
}




int solve(int A[], int n1, int B[], int n2, int ans[], int k){
    int index = 0;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(A[i] == B[j]){
            ans[index++] = A[i];
            i++;
            j++;
        }else{
            if(A[i] > B[j]){
                j++;
            }else{
                i++;
            }
        }
    }
    
    return index;
}

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    int k = max(n1, n2);
    int *temp = new int[k];
    int n4 = solve(A, n1, B, n2, temp, k);
    k = max(n2, n3);
    int *temp2 = new int[k];
    int n5 = solve(C, n3, temp, n4, temp2, k);
    set<int> sett;
    vector<int> ans;
    for(int i = 0; i < n5; i++){
        sett.insert(temp2[i]);
    }
    
    for(auto i : sett){
        ans.push_back(i);
    }
    
    return ans;
}