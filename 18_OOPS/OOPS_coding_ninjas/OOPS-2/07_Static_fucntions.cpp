#include<iostream>
using namespace std;

class Student{
    public:
    int age;
    int rollno;
    static int totalstudents; // ->  declaring static data members


    Student(int age, int rollno){
        cout<<"Constructor Called"<<endl;
        this -> age = age;
        this -> rollno = rollno;
        totalstudents++;
    }

    ~Student(){
        cout<<"Destructor Called"<<endl;
    }

    static int gettotalstudents(){
      return totalstudents;
    }
};

int Student :: totalstudents = 0; // -> initializing the static property

int main(){

    Student s1(18, 992);
    static Student s2(18,993); // -> Declaring Static Object

    cout<<s1.age<<" "<<s1.rollno<<endl;
    cout<<s2.age<<" "<<s2.rollno<<endl;

    cout<<Student :: totalstudents<<endl; // -> accessing the static property
    cout<<Student :: gettotalstudents()<<endl; // -> accessing the static functions
    cout<<"End of Main"<<endl;
return 0;
}
