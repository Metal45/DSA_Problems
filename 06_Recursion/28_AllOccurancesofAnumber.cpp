// M - 1
// TC -> O(N) SC 0(N)

void solve(int input[], int size, int i, int &index, int x, int output[]){
  if(i == size){
    return;
  }

  if(input[i] == x){
    output[index] = i;
    index++;
  }

  solve(input, size, i + 1, index, x, output);
}

int allIndexes(int input[], int size, int x, int output[]) {
  int index = 0;
  solve(input, size, 0, index, x, output);
  return index;
}



