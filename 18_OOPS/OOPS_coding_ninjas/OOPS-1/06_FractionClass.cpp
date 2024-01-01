#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
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

    Fraction add(Fraction const &f){
        int lcm = denominator * f.denominator; 
        int x = lcm/ denominator;
        int y = lcm/ f.denominator;
        int num = x* numerator + (y * f.numerator);
        Fraction Fnew(num, lcm);
        Fnew.simplify();
        return Fnew;
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
    Fraction F3 =f1.add(f2);
    f1.print();
    f2.print();
    F3.print();
   
    // f1.multilpy(f2);
    // f1.print();
    // f2.print();
return 0; 
}