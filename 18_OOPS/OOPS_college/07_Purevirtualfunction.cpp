#include<iostream>
using namespace std;

class A{
    public:
    virtual void show()=0;
}; // -> This is an abstract class

void A :: show(){
    cout<<"Definition of a pure virtual function";
} // -> the Pure Virtual function must be defined outside 
// the class definition. If you will define it inside the class 
// definition, complier will give an error. 

class B: public A{
    public:
    void show(){
        cout<<"Implementation of pure virtual function in Derived class";
    }
};

int main(){
    
    // A a;  
    // -> you can not create an object of abstract class
    A *a;
    B b;
    a = &b;
    a -> show();
}