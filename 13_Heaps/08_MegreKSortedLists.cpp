// It is exactly similar to the last question, time and space is also same

#include <iostream>
#include <queue>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode(int val){
        this -> val = val;
        next = NULL;
    }
};

class cmp{
    public:
    bool operator()(ListNode *a, ListNode *b){
        return a -> val > b -> val;
    }
};

class Solution {
public:
    // similar logic to merge K sorted Linked List

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using heaps
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        int k = lists.size();

        if(k == 0){
            return NULL;
        }

        // pushing head of every linked list
        for(int i = 0; i < k; i++){
            ListNode *curr = lists[i];
            if(curr != NULL){
                minHeap.push(curr);
            }
        }

        ListNode *head = NULL, *tail = NULL;

        while(!minHeap.empty()){
            ListNode *curr = minHeap.top();
            minHeap.pop();

            if(head == NULL){
                head = curr;
                tail = curr;
            }else{
                tail -> next = curr;
                tail = curr;
            }

            if(tail -> next != NULL){
                minHeap.push(tail -> next);
            }
        }


        return head;
    }
};