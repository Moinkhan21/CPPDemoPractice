#include <iostream>
using namespace std;

// ===============================
// Definition of Node structure
// ===============================
class Node {
public:
    int data;      // Data part of the node
    Node* next;    // Pointer to the next node in the list

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized constructor to assign data during creation
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ===============================
// Function to insert a node at the end (tail)
// ===============================
void insertAtTail(Node*& head, Node*& tail, int data) {
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: If the list is empty, both head and tail point to the new node
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Otherwise, link the new node after the current tail
    tail->next = newNode;

    // Step 4: Update the tail pointer to the new node
    tail = newNode;
}

// ===============================
// Function to print the linked list
// ===============================
void print(Node* head) {
    Node* temp = head;

    // Traverse through the linked list and print each node's data
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ===============================
// Function to reverse the linked list using iteration
// ===============================
Node* reverseUsingLoop(Node* head) {
    Node* prev = NULL;   // This will point to the previous node (initially NULL)
    Node* curr = head;   // This will point to the current node being processed

    // Traverse the linked list until all nodes are reversed
    while (curr != NULL) {
        Node* temp = curr->next;  // Step 1: Store the next node before breaking the link

        curr->next = prev;        // Step 2: Reverse the link (make current node point to previous)

        prev = curr;              // Step 3: Move `prev` one step forward
        curr = temp;              // Step 4: Move `curr` one step forward (to the original next)
    }

    // Step 5: At the end, `prev` will be pointing to the new head of the reversed list
    return prev;
}

// ===============================
// Main function
// ===============================
int main() {
    Node* head = NULL;  // Initially, the list is empty
    Node* tail = NULL;  // Tail pointer for efficient insertion

    // Insert elements into the linked list
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original Linked List:" << endl;
    print(head);

    // Reverse the linked list using iteration
    head = reverseUsingLoop(head);

    cout << "\nReversed Linked List (Using Iteration):" << endl;
    print(head);

    return 0;
}
