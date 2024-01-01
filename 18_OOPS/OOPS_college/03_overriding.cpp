#include<iostream>
using namespace std;

class A{
    public:
    void show(){
        cout<<"This is base class";
    }
};

class B: public A{
    public:
    void show(){
        cout<<"This is child class";
    }
};

int main(){

    B obj;
    obj.show();

    return 0;
}