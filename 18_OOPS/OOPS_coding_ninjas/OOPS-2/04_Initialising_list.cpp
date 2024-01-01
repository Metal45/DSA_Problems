#include<iostream>
using namespace std;

class student{
    public:
    int age;
    const int rollno;
    int &x;


    // -> initialization list is used to initialise const and reference variables
    // -> you can also use initialization list for intitialization list for non constant members 
    // -> while initializing the constant variables you dont need to use this keyword(if argument name is same as the variable name) as ther is no confusion between both
    // -> but while initializing refennce variables you need to use this keyword

    student(int age, int rollno) : rollno(rollno), x(this -> age){
        this -> age = age;
    }

    void display(){
        cout<<"age: "<<age<<endl;
        cout<<"rollno: "<<rollno<<endl;
    }
};
    
int main(){ 
    student s1(20, 101);
    s1.display(); 
return 0; 
}