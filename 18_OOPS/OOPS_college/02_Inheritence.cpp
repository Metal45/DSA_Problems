#include <iostream>
using namespace std;

class A{
    public:
    
    A(){
        cout<<"Contsructor called"<<endl;}
    ~A(){
        cout<<"Destructor called"<<endl;}
};

class B: public A{
    public:
    B(){
    cout<<"B called"<<endl;}
    ~B(){
    cout<<"B destructed"<<endl;}
};


int main() {
        B obj;
    return 0;
}