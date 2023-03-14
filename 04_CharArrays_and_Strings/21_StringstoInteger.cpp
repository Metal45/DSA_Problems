int myAtoi(string s) {
    int num = 0, i = 0, sign = 1;

    // ignoring leading whitespaces
    while(s[i] == ' '){
        i++;
    }

    // checking the sign 
    if(i < s.size() && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '+'){
            sign = 1;
        }else{
            sign = -1;
        }
        i++;
    }

    // forming a number until we ecnoutner a non digit number
    while(i < s.size() && isdigit(s[i])){
        // out of range of int check
        if(num > INT_MAX/10 || (num == INT_MAX/10 && (s[i] - '0' > 7))){
            if(sign == 1){
                return INT_MAX;
            }else{
                return INT_MIN;
            }
        }
        
        num = num * 10 + (s[i] - '0');
        i++;
    }

    return num*sign;
}  