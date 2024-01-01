#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    int Health;
    public:
    char *name;
    char level;

    Hero(Hero const &h){
        // -> deep copy with copy constructor
        this -> Health = h.Health;
        this -> level = h.level;
        // this -> name = new char[strlen(name) + 1];
        // strcpy(this -> name, name);

        char *c = new char[strlen(h.name) + 1];
        strcpy(c, h.name);
        this -> name = c;
    }

    Hero(int Health, char level, char *name){
        //->deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
        this -> Health = Health;
        this -> level = level;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Health: "<<Health<<endl;
        cout<<"Level: "<<level<<endl;
    }
};

int main(){ 
char name[] = "abcd";
Hero h1(20, 'A', name);
Hero h2(21, 'B', name);
Hero h3(h1);
h1.display();
h2.display();
h3.display();
cout<<endl;
h2.name[0] = 'n';
h1.display();
h2.display();
return 0; 
}