#include<iostream>
using namespace std;

class A{
    public:
    void show(){
        cout<<"Base class"<<endl;
    }
};

class B: public A{
    public:
    void show(){
        cout<<"Derived class"<<endl;
    }
};

int main(){
    A *obj1;
    B obj2;
    obj1 = &obj2;
    obj1 ->show(); //Early binding occurs as cpmplier sees the pointer oof base class pointing towards the object of the show function of the base class

}