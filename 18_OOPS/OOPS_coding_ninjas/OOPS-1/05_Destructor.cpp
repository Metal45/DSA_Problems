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
    ~student(){
        cout<<"Destructor Called ! for: "<<this<<endl;
    }
    void display(){ 
        cout<<age<<" "<<rollno<<endl;
    }
};

int main(){ 

student s1(18, 50);
student s2(s1);
student *s3 = new student(19,21);

s1.display();
s2.display();
s3 -> display();

cout<<"adress: 1 "<<&s1<<endl;
cout<<"adress: 2 "<<&s2<<endl;
cout<<"adress: 3 "<<s3<<endl;


// -> desturctor is called in the  opposite order of constructor 
// -> the objec that is created first gets deleted at the last

delete s3;
return 0; 
}