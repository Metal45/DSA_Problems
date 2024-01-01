#include<iostream>
#include<cstring>
using namespace std;

class Student{
    public:
    int age;
    char *name;

    public:
    Student(int age, char *name){
        this -> age = age;
        // -> shallow copy;

        // -> default copy constructor also does shallow copy
        // -> so for deep copy you will have to create your own constructor 
        //this -> name = name;

        

        // -> Deep copy

        // -> one way to do deep copy
        // char *ch = new char[strlen(name) + 1];
        // strcpy(ch, name);
        // strcpy(this -> name, ch);

        // ->2nd way to do deep copy;
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }  
 
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

int main(){ 
    char name[] ="abcd";
    Student s1(18, name);
    Student s2(s1);
    Student s3(19, name);

    s2.name[0] = 'N';
    s3.name[0] = 'M'; //-> it changes 
    // the name of both the objects not only of s2 
    // this is due to shallow copy as we are accessing 
    // the same memory as no new memory is created for the name
    // of s2 the memory locations of name of s1, s2 and s3 are same


    s1.display();
    s2.display();
    s3.display();
}