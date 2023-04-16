map<char, int> Symbols{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

// We convert Roman to Interger from Left To Right with with values of roman symbols decreasing so you need to keep in mind these things ->
// Approach -> 
// 1. Create a map with and map the values of roman symbols with their int values
// 2. Now traverse on the string and fetch the values of that symbol from map and add in the ans
// 3. Now the two char symbols are where the first's value is decreased from second's value like CM -> -100 + 1000
// 4. So if value of char at i is less than i + 1  decrease it's value from ans else keep on adding values of the roman sybmbols 
int romanToInt(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(Symbols[s[i]] < Symbols[s[i + 1]]){
            ans -= Symbols[s[i]];
        }else{
            ans += Symbols[s[i]];
        }
    }

    return ans;
}