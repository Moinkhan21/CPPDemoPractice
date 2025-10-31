#include <iostream>
using namespace std;

Node* copyRandomList(Node* head) {
    if(!head) return 0;

    //Step 1: Clone A -> A'
    Node*it = head; //Iterate over old head
    while(it) {
        Node*clonedNode = new Node(it -> val);
        clonedNode -> next = it -> next;
        it -> next = clonedNode;
        it = it -> next -> next;
    }

    //Step 2: Assign random links of A' with the helper of A
    it = head;
    while(it) {
        Node* clonedNode = it -> next;
        clonedNode -> random = it -> random ? it -> random -> next : nullptr;
        it = it -> next -> next;
    }

    //Step 3: Detach A' form A
    it = head;
    Node* clonedHead = it -> next;
    while(it) {
        Node* clonedNode = it -> next;
        it -> next = it -> next -> next;
        if(clonedNode-> next){
            clonedNode -> next = clonedNode -> next -> next;
        }
        it = it -> next;
    }
    return clonedHead;
} 