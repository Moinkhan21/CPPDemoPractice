#include <iostream>
using namespace std;

// ============================================================================
//  CLASS DEFINITION: Node
//  ----------------------
//  A Node represents one element of a Linked List. Each node stores:
//    - An integer 'data' (the actual value).
//    - A pointer 'next' that points to the next node in the list.
// ============================================================================
class Node {
public:
    int data;     // To store the value inside the node
    Node* next;   // Pointer to the next node

    // Default Constructor
    // Initializes data as 0 and next as NULL (empty link)
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized Constructor
    // Initializes node with a given data value and sets next to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ============================================================================
//  FUNCTION: insertAtHead
//  ----------------------
//  Purpose  : Inserts a new node at the **beginning (head)** of the Linked List.
//  Parameters:
//      - Node*& head : Reference to the head pointer (so we can modify it).
//      - Node*& tail : Reference to the tail pointer (used when list is empty).
//      - int data    : Value to be inserted into the new node.
//
//  Logic:
//      1. If the list is empty (tail == NULL), create the first node.
//      2. Create a new node and set its next pointer to the current head.
//      3. Update head to point to the new node (making it the new first node).
// ============================================================================
void insertAtHead(Node*& head, Node*& tail, int data) {

    // CASE 1: Empty Linked List (no head, no tail)
    if (tail == NULL) {
        Node* newNode = new Node(data); // Create first node
        tail = newNode;  // Both head and tail point to this new node
        head = newNode;
        return;  // Exit after creating the first node
    }

    // CASE 2: Non-empty list
    // Step 1: Create a new node with given data
    Node* newNode = new Node(data);

    // Step 2: Link the new node to the current head node
    newNode->next = head;

    // Step 3: Move head pointer to the new node
    head = newNode;
}

// ============================================================================
//  FUNCTION: insertAtTail
//  ----------------------
//  Purpose  : Inserts a new node at the **end (tail)** of the Linked List.
//  Parameters:
//      - Node* head  : Pointer to the head node (not modified here).
//      - Node*& tail : Reference to the tail pointer (to update it).
//      - int data    : Value to be inserted into the new node.
//
//  Logic:
//      1. If list is empty, create the first node and assign head & tail.
//      2. Create a new node and connect it to the last node (tail).
//      3. Update the tail pointer to point to this new node.
// ============================================================================
void insertAtTail(Node* head, Node*& tail, int data) {

    // CASE 1: Empty Linked List (no head, no tail)
    if (tail == NULL) {
        Node* newNode = new Node(data);  // Create first node
        tail = newNode;
        head = newNode;
        return;
    }

    // CASE 2: Non-empty list
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Link current tail node to the new node
    tail->next = newNode;

    // Step 3: Update tail to point to the new node (new end)
    tail = newNode;
}

// ============================================================================
//  FUNCTION: print
//  ---------------
//  Purpose  : Prints all elements of the Linked List starting from head.
//  Parameters:
//      - Node* head : Pointer to the head node of the list.
//
//  Logic:
//      Traverse through the list using a temporary pointer and print each node’s data.
// ============================================================================
void print(Node* head) {
    Node* temp = head;  // Temporary pointer for traversal
    while (temp != NULL) {
        cout << temp->data << " ";  // Print data of each node
        temp = temp->next;          // Move to next node
    }
    cout << endl;  // New line after printing the list
}

// ============================================================================
//  FUNCTION: main
//  --------------
//  Purpose: Demonstrates Linked List creation and insertion operations.
// ============================================================================
int main() {
    Node* head = NULL;  // Initially the list is empty
    Node* tail = NULL;  // Both head and tail are NULL

    // Insert nodes at the head (new nodes become the first element)
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);

    // Insert node at the tail (new node added at the end)
    insertAtTail(head, tail, 77);

    // Display all elements of the list
    cout << "Printing the Linked List:" << endl;
    print(head);

    return 0;  // End of program
}
