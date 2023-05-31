#include <iostream>
#include <queue>
using namespace std;

// Learn more about on priortiy queue on cpp reference 
int main(){
    // maxheap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);


    // minheap
    priority_queue<int, vector<int>, greater<int>> pq;


    // // fucntions 
    // pq.push()
    // pq.pop();
    // pq.top();
    // pq.empty();
    // pq.size();

}