#include <iostream>
using namespace std;

Node *evenAfterOdd(Node *head)
{
	//write your code here 
    // approach create two sublists Ohead and Ehead with the help of traversing over the LL with head and then rearrgange the pointers
    // rearrnge the pointers accurately
    if(head == NULL){
        return head;
    }

    Node *Ohead = NULL;
    Node *Ehead = NULL;
    Node *Otail = NULL;
    Node *Etail = NULL;

    while(head != NULL){
        if(head-> data % 2 == 0){
            if(Ehead == NULL){
                Ehead = head;
                Etail = head;
            }else{
               Etail->next = head;
               Etail = head;
            }
        }else{
            if(Ohead == NULL){
                Ohead = head;
                Otail = head;
            }else{ // Bina is else ke error kyud de rha hai
               Otail->next = head;
               Otail = head;
            }
        }
        head = head -> next;
    }

    // All these if else conditions are important
    if(Ohead ==NULL){
        return Ehead;
    }else{
      Otail->next = Ehead;
    }

    if(Ehead != NULL){ // if Ehead is NULL then Etail will alsio be null so you will access null -> next which is not possible 
       Etail->next = NULL;
    }
    
    return Ohead;
}