using namespace std;
#include <vector>

vector<vector<int>>ans;
void helpsub(vector<int>&nums,vector<int>subset,int i) {
    if (i==nums.size()) {
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    helpsub(nums,subset,i+1);

    subset.pop_back();
    helpsub(nums,subset,i+1);
}

vector<vector<int>>subsets(vector<int>&nums) {
    vector<int>subset;
    helpsub(nums,subset,0);
    return ans;
}