#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(!head) return NULL;

    // Step 1: Clone each node and place the cloned node after the original
    Node* it = head;
    while(it) {
        Node* clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = clonedNode->next;
    }

    // Step 2: Assign random pointers to cloned nodes
    it = head;
    while(it) {
        if(it->random)
            it->next->random = it->random->next;
        it = it->next->next;
    }

    // Step 3: Separate original and cloned lists
    it = head;
    Node* clonedHead = head->next;
    while(it) {
        Node* clonedNode = it->next;
        it->next = clonedNode->next;
        if(clonedNode->next)
            clonedNode->next = clonedNode->next->next;
        it = it->next;
    }
    
    return clonedHead;
}

// Utility: print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << "Node: " << temp->val;
        if(temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Create LL: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assign random pointers
    head->random = head->next;               // 1 -> 2
    head->next->random = head->next->next;   // 2 -> 3
    head->next->next->random = head;         // 3 -> 1

    cout << "Original List:\n";
    printList(head);

    Node* cloned = copyRandomList(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}
