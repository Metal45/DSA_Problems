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
                if(numerator % i == 0 && denominator % i == 0){
                    hcf = i;
                }
             }
            numerator = numerator / hcf;
            denominator = denominator / hcf;
        }

    Fraction operator+(Fraction const &f) const{
        int lcm = denominator * f.denominator; 
        int x = lcm/ denominator;
        int y = lcm/ f.denominator;
        int num = x* numerator + (y * f.numerator);
        Fraction Fnew(num, lcm);
        Fnew.simplify();
        return Fnew;
    }

    Fraction operator*(Fraction  const &f) const{
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        Fraction Fnew(n,d);
        Fnew.simplify();
        return Fnew;
    }

    bool operator==(Fraction const &f) const{
        return (numerator == f.numerator && denominator == f.denominator);
    }
  
};
 
int main(){ 
    Fraction f1(10, 2);
    Fraction f2(10, 2);
    Fraction F3 = f1 + f2;
    f1.print();
    f2.print();
    F3.print();
   
    Fraction F4 = f1 * f2;
    f1.print();
    f2.print();
    F4.print();

    if(f1 == f2){
        cout<<"Equal"<<endl;
    }else{
        cout<<"Unequal"<<endl;
    }
return 0; 
}