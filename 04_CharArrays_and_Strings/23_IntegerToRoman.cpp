string intToRoman(int num) {
    // mapping roman symbols to their values
    vector<string> RomanSymbols = {"M", "CM", "D", "CD", "C", "XC" , "L", "XL" , "X", "IX", "V", "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";

    // converting integer to roman symbols 
    for(int i = 0; i < 13; i++){
        while(num >= values[i]){
            ans += RomanSymbols[i];
            num -= values[i];
        }
    }

    return ans;
}