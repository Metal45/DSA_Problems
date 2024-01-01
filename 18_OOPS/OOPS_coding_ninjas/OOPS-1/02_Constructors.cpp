#include<iostream>
using namespace std;
 
class student{

    private:
    int age;

    public: 
    int rollno;

    public:
    // -> Default constructor
    student(){
        cout<<"Cnstructor called !"<<endl;
    }

    // -> parameterized constructor
    student(int r){
        cout<<"Constuctor 2 called !"<<endl;
        rollno = r;
    }

    student(int r, int a){
        cout<<"Constructor 3 called !"<<endl;
        rollno = r;
        age = a;
    }

    void display(){
        cout<<rollno<<" "<<age<<endl;
    }

    int getage(){ 
        return age;
    }

    void setage(int a){ 
        age = a;
    }
};

int main(){ 
 
    student s1;
    s1.display();

    student s2;

    student *s3 = new student;
    s3 -> display();

    cout<<"parameterized constructor demo"<<endl;

    student s4(10);
    student *s5 = new student(10);
    s4.display();
    s5 ->  display();


    student s6(10, 18);
    student *s7 = new student(11,19);
    s6.display();
    s7 -> display();

return 0; 
}