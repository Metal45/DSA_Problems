#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction(){   
    }

    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    int getnumerator() const{
        return numerator;
    }

    int getdenominator () const{
        return denominator;
    }

    void setnumerator(int n){
        numerator  = n;
    }

    void print(){
        cout<<numerator<<" / "<<denominator<<endl;
    }

    void simplify(){
            int hcf = 1;
            int j = min(numerator, denominator);          
            for(int i = 1; i <= j; i++){               
                if(this -> numerator % i == 0 && this -> denominator % i == 0){
                    hcf = i;
                }
             }
            numerator = numerator / hcf;
            denominator = denominator / hcf;
        }

    void add(Fraction const &f){
        int lcm = denominator * f.denominator; 
        int x = lcm/ denominator;
        int y = lcm/ f.denominator;
        int num = x* numerator + (y * f.numerator);
        numerator = num;
        denominator = lcm;
        simplify();
    }

    void multilpy(Fraction  f){
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        simplify();
    }

    
};
 
int main(){ 
Fraction f1(10, 2);
Fraction f2(15, 4);

const Fraction f3(17,8);
cout<<f3.getdenominator()<<" "<<f3.getnumerator()<<endl;
cout<<endl;
return 0; 
}