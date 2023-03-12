// Return the largest odd number in the string

string largestOddNumber(string num) {
    
    for(int i = num.size() - 1; i >= 0; i--){
        if((num[i] - '0') % 2 == 0){
            num.pop_back();
        }else{
            break;
        }
    }

    return num;
    
    // while(!num.empty() && num[num.size() - 1] % 2 == 0){
    //     num.pop_back();
    // }

    // return num;
}