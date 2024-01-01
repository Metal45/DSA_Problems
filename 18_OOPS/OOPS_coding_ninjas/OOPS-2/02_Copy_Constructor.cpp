#include<bits/stdc++.h>
using namespace std;

class student{
    int age;

    public:
    char *name;

    student(int age, char *name){
        this -> age = age;
        this -> name = name;
    }

    student(student const &s){
        this -> age = s.age;
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
    }
    
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};
 
int main(){ 
    char name[] ="abcd";
    student s1(20, name);

    student s2(s1);

    s2.name[0] = 'n';

    s1.display();
    s2.display();

return 0; 
}