#include <iostream>
using namespace std;

class A{

    public:
    A(){
        cout<<"Constructor Called"<<endl;
    }
    virtual ~A(){
        cout<<"Destructor Called"<<endl;
    }
};

class B: public A{

    public:
    B(){
        cout<<"Derived Constructor Called"<<endl;
    }
    ~B(){
        cout<<"Derived Destructor Called"<<endl;
    }
};

int main(){
    A *a = new B;
    delete a;
}