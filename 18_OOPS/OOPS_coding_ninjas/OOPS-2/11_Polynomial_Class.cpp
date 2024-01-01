#include<iostream>
using namespace std;

class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    
    // Complete the class
    int size;
    //int index;
    
    Polynomial(){
        degCoeff = new int[5];
        //index = 0;
        size = 5;
        for(int i = 0; i < size; i++){
            degCoeff[i] = 0;
        }
    } 
    
    Polynomial(Polynomial const &p){
        this -> degCoeff = new int[p.size];
        for(int i = 0; i < p.size; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> size = p.size;  
    }
    
    void operator=(Polynomial const &p){
        this -> degCoeff = new int[p.size];
        for(int i = 0; i < p.size; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> size = p.size;  
    }
    
    void setCoefficient(int degree, int coef){
        while(degree >= size){
            int *newarr = new int[2*size];
            for(int i = 0; i < size; i++) newarr[i] = degCoeff[i];
            for(int i = size/2; i < size; i++) newarr[i] = 0;
            delete []degCoeff;
            degCoeff = newarr;
            size *= 2;
        }
        degCoeff[degree] = coef;
    }
    
    Polynomial operator+(Polynomial &p){
        Polynomial P;
        for(int i = 0; i < size; i++){
            int x = this -> degCoeff[i] + p.degCoeff[i];
            P.setCoefficient(i,x);
        }
        return P;
    }
    
    Polynomial operator-(Polynomial &p){
        Polynomial P;
        for(int i = 0; i < size; i++){
            int x = this -> degCoeff[i] - p.degCoeff[i];
            P.setCoefficient(i,x);
        }
        return P;
    }
    
    Polynomial operator*(Polynomial &p){
        
    }
    
    void print(){
        for(int i = 0; i < size; i++){
    		if(degCoeff[i] != 0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
            cout<<endl;
        }    
	}
};


int main(){ 

int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
return 0; 
}

