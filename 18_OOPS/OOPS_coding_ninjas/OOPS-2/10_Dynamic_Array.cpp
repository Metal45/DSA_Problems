#include<iostream>
using namespace std;
 
class dynamicarr{
    private:
    int *arr;
    int size;
    int index;

    public:
    dynamicarr(){
        arr = new int[5];
        size = 5;
        index = 0;
    }

    dynamicarr(dynamicarr const &d){ // -> copy constructor 
        this -> arr = new int[d.size];
        for(int i = 0; i < d.index; i++){
            this -> arr[i] = d.arr[i];
        }
        this -> size = d.size;
        this -> index = d.index;
    }

    void operator=(dynamicarr const &d){ //-> copy assignment operator
        this -> arr = new int[d.size];
        for(int i = 0; i < d.index; i++){
            this -> arr[i] = d.arr[i];
        }
        this -> size = d.size;
        this -> index = d.index;
    }

    void add(int element){

        if(index == size){
            int *newarr = new int[2*size];
            for(int i = 0; i < size; i++) newarr[i] = arr[i];
            delete []arr;
            arr = newarr;
            size = 2*size;
        }
        arr[index] = element;
        index++;
    }

    int getelement(int i) const{
        if(i < index) return arr[i];
        else return -1;
    }

    void add(int i, int element){
        if(i < index) arr[i] = element;
        else if(i == index) add(element);
        else return ;
    }

    void print() const{
        for(int i = 0; i < index; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){ 
dynamicarr d;
d.add(10);
d.add(20);
d.add(30);
d.add(40);
d.add(50);
d.add(60);

dynamicarr d1(d); // -> here the defualt copy construtor does shallow copy which is a problem;
dynamicarr d2;
d2 = d; // -> here the defualt copy assignment opeartor does shallow copy which is a problem;

d.add(0,100);
d.print();
d1.print();
d2.print();
return 0; 
}