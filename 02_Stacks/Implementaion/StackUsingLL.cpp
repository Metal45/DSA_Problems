#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

class Stack{
    private:
    Node *head;
    int Size;

    public:
    Stack(){
        head = NULL;
        Size = 0;
    }

    void push(int val){
        Node *temp = new Node(val);
        temp -> next = head;
        head = temp;
        Size++;
    }

    void pop(){
        if(Size == 0){
            return;
        }
        Node *temp = head;
        head = head -> next;
        delete temp;
        Size--;
    }

    int top(){
        if(Size == 0){
            return INT_MIN;
        }
        return head -> data;
    }

    int size(){
        return Size;
    }

    bool empty(){
        return Size == 0;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
}