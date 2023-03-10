#include <iostream>
using namespace std;
#include <stack>


// stack is a LIFO data structure that is last in first out, the elements that is the last element comes out first 


// stack can be implemented using arrays and linked list both and is also present in STL 
// implementing stack using an array 
class Stack{
    private:
    int *data;
    int nextindex;
    int capacity;

    public:
    Stack(){
        data = new int[4];
        nextindex = 0;
        capacity = 4;
    }

    int size(){
        return nextindex;
    }

    bool empty(){
        return nextindex == 0;
    }

    void push(int value){
        if(nextindex == capacity){
           int *newData = new int[2*capacity];
           for(int i = 0; i < capacity; i++) newData[i] = data[i];
           delete []data;
           data = newData;
           capacity *= 2;
        }
        data[nextindex] = value;
        nextindex++;
    }

    int pop(){
        if(empty()){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    int top(){
        if(empty()){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        return data[nextindex - 1];
    }
};




int main(){
    Stack s;
    s.push(5);
    s.push(2);
    // inserts elements into stack 

    s.pop();
    // removes the top element of stack

    cout << s.empty() << endl;
    // tells if the stack is empty or not 

    cout << s.size() << endl;
    // returns the size of stack

    cout<< s.top() << endl;
    // returns the top element of the stack
}


