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

    // void operator++(){
    //     numerator = numerator + denominator;
    //     simplify();
    // }

    // pre increment operator 
    Fraction& operator++(){
        numerator = numerator + denominator;
        simplify();
        return *this;
    }
    // post increment operator
    Fraction operator++(int){
        Fraction Fnew(numerator, denominator);
        numerator = numerator + denominator;
        Fnew.simplify();
        simplify();
        return Fnew;   
    }

    // Fraction operator++(){
    //     int n = numerator + denominator;
    //     numerator = n;    
    //     int d = denominator;
    //     Fraction Fnew(n,d);
    //     Fnew.simplify();
    //     simplify();
    //     return Fnew;
    //}

    Fraction& operator+=(Fraction const &F){
        int n = (numerator * F.denominator) + (F.numerator * denominator);
        int d = (denominator * F.denominator);
        numerator = n;
        denominator = d;
        simplify();
        return *this;
    }
};
 
int main(){ 
    Fraction f1(10, 2);
    Fraction f3(6, 2);
    (f1 += f3) += f3;
    //Fraction F3 = ++(++f1);
    //Fraction F3 = f1++;
    f1.print();
    f3.print();
return 0;  
}