
// TC / SC -> O(Max(Len1, Len2))

void solve(string &num1, string &num2, string &Output, int i, int j, int &carry){
    if(i < 0 && j < 0 && carry <= 0){
        return ;
    }

    int sum = 0;
    if(i >= 0){
        sum += num1[i] - '0';
    }

    if(j >= 0){
        sum += num2[j] - '0';
    }

    if(carry > 0){
        sum += carry;
    }

    carry = sum / 10;
    Output += (sum % 10)+ '0';
    solve(num1, num2, Output, i - 1, j - 1, carry);
}   

string addStrings(string num1, string num2) {
    string output = "";
    int carry = 0;
    solve(num1, num2, output, num1.size() - 1, num2.size() - 1, carry);
    reverse(output.begin(), output.end());
    return output;
}