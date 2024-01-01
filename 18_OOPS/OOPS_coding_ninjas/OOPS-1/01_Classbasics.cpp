#include<iostream>
using namespace std;

class Product{
    int id;
    int weight;
    char name[100];
};


class Student{
    public:
    int rollno;

    private:
    int age;

    public:
    void display(){
        cout<<rollno<<" "<<age<<endl;
    }
    int getage(){  // -> generally called a getter function
        return age;
    }
    void setage(int a){ // -> generally called a setter function
    }
};

int main(){
    Student s1; // -> creating object statically
    Student *s2 = new Student(); // ->creating object dynamically
    Student *s3 = new Student;  // another syntax to allocate object dynamically

    //s1.age = 11; // -> as age is private you can not access the age
    s1.setage(11);
    s1.rollno = 991;

   
    //(*s2).age = 12;
    (*s2).setage(12);
    (*s2).rollno = 992;

    //s3 -> age = 13;
    s3 -> setage(13);
    s3 -> rollno = 993;

    s1.display();
    (*s2).display();
    s3 -> display();
    cout<<s1.getage()<<endl;
    cout<<(*s2).getage()<<endl;
    cout<<s2 -> getage()<<endl;
    return 0;
}
