#include<iostream>
using namespace std;
 
class student{
    public:
    int rollno;
    int age;

    student(int rollno){
        this -> rollno = rollno;
    }
    
    student(int a, int r){
        cout<<"this : "<<this<<endl;
        age = a;
        rollno = r;
    }

    void display(){
        cout<<age<<" "<<rollno<<endl;
    }
};

int main(){ 
    student s1(91);
    cout<<"Adress of S1: "<<&s1<<endl;
    s1.display();
return 0; 
}