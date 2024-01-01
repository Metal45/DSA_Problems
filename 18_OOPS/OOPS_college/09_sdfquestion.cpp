#include<iostream>
#include<string.h>
using namespace std;

class person{
    
    public:
    string name;
    float gpa;
    int pub;

    virtual void getData()=0;
    virtual void isoutstanding()=0;

    void input(){
        cout<<"Enter the namevof the person: ";
        cin>>name;
    }

    void display(){
        cout<<"name of the person is: "<<name<<endl;
    }
};


class student: public person{
    public:
    void getData(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the Gpa of the student: ";
        cin>>gpa;
    }
    void isoutstanding(){
        if(gpa>3){
            cout<<"Outstanding"<<endl;
        } else{
            cout<<"Not Outstanding"<<endl;
        }
    }
};


class instructor: public person{
    public:
    void getData(){
        cout<<"Enter the name of the Instructor: ";
        cin>>name;
        cout<<"Enter the no. of publications by the instructor: ";
        cin>>pub;
    }
    void isoutstanding(){
        if(pub>3){
            cout<<"Outstanding"<<endl;
        } else{
            cout<<"Not Outstanding"<<endl;
        }
    }
};

int main(){
 
    instructor  obj[3];
    student obj1[3];
    
    for(int i= 0; i < 3; i++){
        obj1[i].getData();
    }
    
    for(int i= 0; i < 3; i++){
        obj[i].getData();
    }
    
    for(int i = 0; i < 3; i++){
        obj1[i].display();
        obj1[i].isoutstanding();
    }
    
    for(int i = 0; i < 3; i++){
        obj[i].display();
        obj[i].isoutstanding();
    } 
}




