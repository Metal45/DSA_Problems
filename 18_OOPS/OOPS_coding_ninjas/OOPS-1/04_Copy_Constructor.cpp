#include<iostream>
using namespace std;

class student{
    public:
    int rollno;
    int age;
    
    student(int a, int r){
        cout<<"Constructor Called !"<<endl;
        age = a;
        rollno = r;
    }

    void display(){
        cout<<age<<" "<<rollno<<endl;
    }
};
 
int main(){ 

// -> copy constructor;
student s1(10, 992);
s1.display();

student s2(s1); // -> copy constructor called
student *s7 = new student(s1); // -> copy constructor called

s7 -> display();
s2.display();
cout<<endl;

student *s3 = new student(11, 993);
student *s4 = new student(*s3); // -> copy constructor called
student s5(*s3); // -> copy constructor called


s3 -> display();
s4 -> display();
s5.display();
cout<<endl;

// -> copy assignment operator
student o1(18, 990);
student o2(11, 564);
o1.display();
o2.display();

o2 = o1; // -> copy the data members of o1 to o2
o2.display();
cout<<endl;

student o3 = o1; // -> copy constructor called
o3.display();

return 0; 
}