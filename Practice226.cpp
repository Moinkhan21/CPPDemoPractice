#include <iostream>
using namespace std;

// Node structure definition
class Node {
public:
    int data;
    Node* next;     // Points to next linked list (horizontally)
    Node* bottom;   // Points to the next element in the same vertical list

    Node(int val) {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two bottom-sorted linked lists
Node* merge(Node* a, Node* b) {
    // If first list ends, return second
    if(!a) return b;

    // If second list ends, return first
    if(!b) return a;

    Node* ans;

    /*
       Compare heads of both bottom lists
       Attach the smaller one to result and recursively merge remaining list
    */
    if(a->data < b->data) {
        ans = a;  
        ans->bottom = merge(a->bottom, b); // Move downwards in list a
    } else {
        ans = b;  
        ans->bottom = merge(a, b->bottom); // Move downwards in list b
    }

    ans->next = NULL;  // Important: remove horizontal links
    return ans;        // Return head of merged list
}

// Flatten the list
Node* flatten(Node* root) {
    // Base case: If empty or only one list, return it
    if(!root) return NULL;
    if(!root->next) return root;

    // Flatten the rest of the list first (right side lists)
    root->next = flatten(root->next);

    // Merge current vertical list with already flattened right side
    root = merge(root, root->next);

    return root; // Return head of fully flattened list
}

// Print bottom-linked list
void printList(Node *root) {
    while (root) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

// Driver code
int main() {
    /*
        Input structure:
        5 -> 10 -> 19 -> 28
        |     |     |     |
        7     20    22    35
        |           |     |
        8           50    40
        |                 |
        30                45

        Output after flattening:
        5 7 8 10 19 20 22 28 30 35 40 45 50
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    // Call flatten function to convert to single sorted list
    head = flatten(head);

    cout << "Flattened list: ";
    printList(head);

    return 0;
}
