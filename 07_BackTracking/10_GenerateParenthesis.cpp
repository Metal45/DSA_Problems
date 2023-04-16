class Solution {
public:
    void helper(vector<string> &ans, string &output, int n, int open, int close){
        // base case
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }

        // including open bracket 
        if(open > 0){
            output.push_back('(');
            helper(ans, output, n, open - 1, close);
            // backtracking
            output.pop_back();
        }

        // including close bracket
        if(close > open){
            output.push_back(')');
            helper(ans, output, n, open, close - 1);
            // backtracking
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        helper(ans, output, n, n, n);
        return ans;
    }
};