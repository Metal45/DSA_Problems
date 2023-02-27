// There is an element that is dupicate appears twice and all other elements appears 
// exactly once. Find the element that appears twice

int duplicateNumber(int *arr, int size)
{
   // Optimal Approach -> TC O(N) SC O(1)
   // 1. Using XOR -> Xor the array num with their indices
   // 2. Using Sum -> subtract the array sum and sum of 0 to n -2 numbers

   int answer = 0;
   for (int i = 0; i <= size - 2; i++) {
        answer ^= i;
    }

    for(int i = 0; i < size; i++){
        answer = arr[i] ^ i;
    }

    return answer;




    //  // Better Approach, Using Hashmaps -> TC O(N) SC O(N)  

    //  //  Brute Force -> iterate over the array and check if the element is present there in right side 
    //  //  TC -> O(N2) SC O(1)

    //    for (int i = 0; i < size - 1; i++) {
    //     for (int j = i + 1; j < size; j++) {
    //             if (arr[i] == arr[j]) {
    //             return arr[j];
    //             }
    //         }
    //     }
}    