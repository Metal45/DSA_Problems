
// Better
// You start putting 1 to n on every position and keep on doing it if it satisfies the condition 
class Solution {
public:
    void solve(vector<int> &temp, int n, int currNum, int &ans){
        if(currNum == n + 1){
            ans++;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(temp[i] == 0 && (i % currNum == 0 || currNum % i == 0)){
                temp[i] = currNum;
                solve(temp, n, currNum + 1, ans);
                temp[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        int ans = 0;
        vector<int> temp(n + 1, 0);
        solve(temp, n, 1, ans);
        return ans;
    }
};






class Solution {
public:

    // brute force 
    bool isBeautiful(string temp, int n){
        for(int i = 0; i < temp.size(); i++){
            if(((temp[i] - '0') % (i + 1) == 0) || ((i + 1) % (temp[i] - '0') == 0)){
                continue;
            }else{
                cout << "No for " << temp << " for " << temp[i] << " " << i + 1;
                return false;
            }
        }

        return true;
    }

    void solve(string &nums, int index, int &count){
        if(index == nums.size()){
            if(isBeautiful(nums, nums.size())){
                count++;
            };
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, index + 1, count);
            swap(nums[i], nums[index]);
        }
    }

    int countArrangement(int n) {
        string temp = "";
        for(int i = 1; i <= n; i++){
            temp += i + '0';
        }

        cout << temp << endl;
        int count = 0;
        solve(temp, 0, count);
        return count;
    }
};