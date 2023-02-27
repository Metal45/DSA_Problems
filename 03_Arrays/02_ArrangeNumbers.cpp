
// Your task is to populate the array using the integer values in the range 1 to N
// (both inclusive) in the order - 1,3,5,.......,6,4,2.
void arrange(int *arr, int n)
{
   // Approach -> TC O(N) SC O(1)
    int a = 0, b = n - 1;

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            arr[b] = i;
            b--;
        }else{
            arr[a] = i;
            a++;
        }
    }
    
    
    
    
    // int a = 0, b = n - 1;
	// int val = 1;
    // for(int i = 1 ; i <= n; ){
    //     arr[a] = i;
    //     i++;

    //     if(a == b){
    //         continue;
    //     }
    //     arr[b] = i;
    //     i++;
    //     a++;
    //     b--;
    // }
    
    

//     int val = 1;

//     for(int i = 0; i <= (n - 1)/2; i++){  
//         arr[i]=val;
//         val += 2;
//     }

//     if(n % 2 == 0){
//         val = n;
//     }else{
//         val = n - 1;
//     }
    
//     for(int j = (n + 1)/2 ; j <= n - 1; j++){
//         arr[j]= val;
//         val -= 2;
//     }
    
}