// pick not pick
// return sum of all subsets (distinct)

void helper(vector<int> &arr,int index, vector<int> &ans, int sum){
    if(index == arr.size()){
        ans.push_back(sum);
        return;
    }
    
    helper(arr, index + 1, ans, sum + arr[index]);
    helper(arr, index + 1, ans, sum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    helper(arr, 0, ans, 0);
    return ans;
}