#include<iostream>
using namespace std;

class Student{
    public:
    int age;
    int rollno;
    static int totalstudents; // ->  declaring static data members


    Student(){
        cout<<"Constructor Called"<<endl;
    };

    ~Student(){
        cout<<"Destructor Called"<<endl;
    }
};

int Student::totalstudents = 0;
 
int main(){ 
    int x = 0;
    if(x == 0){
        static Student obj(18,992);
        Student obj2(18,992); 
    }
    // -> as soon as the if ends the scope of obj is over hence it 
    // -> gets destroyed and rest of the main is executed but in case
    // -> of the static object the destructor is called after the main gets over not the if statement
    cout<<"End of Program"<<endl;
return 0; 
}