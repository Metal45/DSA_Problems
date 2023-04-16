#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    
    int Case=1;
    while(test--)
    {
        cout<<"Case #"<<Case<<": ";
        int dig[27];
        for(int i = 0; i <= 26;i++){
            cin>>dig[i];
        }
        
        int N;
        cin >> N;
        map<string,int> freq;
      
        int size =N;
        while(N--)
        {
            string word, temp="";
            cin >> word;
            for(int i=0; i < word.size(); i++)
            {
                int num = dig[word[i]-'A'];
                temp += to_string(num);
            }
            freq[temp]++;
        }
        if(size ==freq.size()){
            cout<<"NO"<< endl;
        }
        else{
           cout<<"YES" << endl; 
        } 
        
        Case++;
    }
}