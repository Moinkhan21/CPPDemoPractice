#include <iostream>
using namespace std;

// Node structure definition
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int val) {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two bottom-sorted linked lists
Node* merge(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;

    Node* ans;

    if(a->data < b->data) {
        ans = a;
        ans->bottom = merge(a->bottom, b);
    } else {
        ans = b;
        ans->bottom = merge(a, b->bottom);
    }
    ans->next = NULL;  // Important: break `next` links
    return ans;
}

// Flatten the list
Node* flatten(Node* root) {
    if(!root) return NULL;
    if(!root->next) return root;

    root->next = flatten(root->next); // Flatten remaining list
    root = merge(root, root->next);   // Merge current with flattened part

    return root;
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

    head = flatten(head);

    cout << "Flattened list: ";
    printList(head);
}
