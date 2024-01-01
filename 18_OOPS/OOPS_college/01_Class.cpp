#include<iostream>
using namespace std;

class Employee{
    string id;
    string name;

    public:
    Employee(){
        cout<<"Enter the Employee id: ";
        cin>>id;
    }

    void SetDetails(){
        cout<<"Enter the Employee's name: ";
        cin>>name;
    }

    void show(){
        cout<<"Employee id of "<<name<<" is "<<id<<endl;
    }
};

int main(){
    Employee E1;
    E1.SetDetails();
    E1.show();
    return 0;
}
