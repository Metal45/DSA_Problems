#include<iostream>
using namespace std;

int main(){
    int a;
    double b;
    int choice;
    try{
        cout<<"Enter a: ";
        cin>>a;
        cout<<"Enter b: ";
        cin>>b;
        cout<<"For integer error enter 1 and 2 for double error: ";
        cin>>choice;
        if(choice==1){
            throw a;
        }
        else if(choice == 2){
            throw b;
        }
        else{
            throw ;
        }
    }
    catch(int x){
        cout<<"Integer error caught of integer: "<<x;
    }
    catch(double y){
        cout<<"Doubl error caught of double: "<<y;
    }
    catch(...){
        cout<<"Default error";
    }
}