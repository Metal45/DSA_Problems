#include<iostream>
using namespace std;

class A{
    public:
    virtual void show(){
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
    obj1 ->show(); 
}


//You cant make a virtual static function because a virtual functions are invoked when you have a pointer or reference to a class
// a static function is tied to a class and in c++ we dont have pointer to a class 