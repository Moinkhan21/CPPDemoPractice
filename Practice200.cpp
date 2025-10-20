#include <iostream>
using namespace std;

// ============================================================================
//  CLASS DEFINITION: Node
//  ----------------------
//  A Node represents one element in a Linked List. Each node contains:
//    1. An integer value (data)
//    2. A pointer to the next node (next)
// ============================================================================
class Node {
public:
    int data;     // To store the value of the node
    Node* next;   // Pointer that links to the next node

    // Default constructor (used when no value is passed)
    Node() {
        this->data = 0;     // Initialize data with 0
        this->next = NULL;  // Initially, next points to nothing (NULL)
    }

    // Parameterized constructor (used when data value is passed)
    Node(int data) {
        this->data = data;  // Assign the passed value to data
        this->next = NULL;  // By default, next is NULL (no next node yet)
    }
};

// ============================================================================
//  FUNCTION: insertAtHead
//  ----------------------
//  Purpose:
//      Inserts a new node right at the **beginning (head)** of the Linked List.
//
//  Parameters:
//      Node*& head : Reference to the head pointer, so we can modify it directly
//      Node*& tail : Reference to the tail pointer (used when list is empty)
//      int data    : The value that will be stored in the new node
//
//  Steps:
//      1️⃣ Create a new node with the given data
//      2️⃣ Point the new node’s next to the current head
//      3️⃣ Move the head pointer to point to the new node
// ============================================================================
void insertAtHead(Node*& head, Node*& tail, int data) {

    // Step 1: Create a new node using the parameterized constructor
    Node* newNode = new Node(data);

    // Step 2: Link the new node to the current head
    // If the list already has elements, the new node should point to the old head
    newNode->next = head;

    // Step 3: Handle the case when the list is empty (head == NULL)
    // If the list was empty, both head and tail should point to the new node
    if (head == NULL) {
        tail = newNode;
    }

    // Step 4: Move head to the new node (it becomes the first node now)
    head = newNode;
}

// ============================================================================
//  FUNCTION: insertAtTail
//  ----------------------
//  Purpose:
//      Inserts a new node right at the **end (tail)** of the Linked List.
//
//  Parameters:
//      Node* head  : Pointer to the head node (not modified here)
//      Node*& tail : Reference to the tail pointer (we modify it)
//      int data    : The value to be inserted at the end
//
//  Steps:
//      1️⃣ Create a new node with the given data
//      2️⃣ If the list is empty, make head and tail point to this new node
//      3️⃣ Otherwise, link the new node at the end using tail->next
//      4️⃣ Move tail pointer to the new node
// ============================================================================
void insertAtTail(Node* head, Node*& tail, int data) {

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Handle the case when the list is empty
    // If tail is NULL, the list has no elements yet
    if (tail == NULL) {
        tail = newNode;   // Both head and tail point to this new node
        head = newNode;
    }
    else {
        // Step 3: Connect the new node after the last node
        tail->next = newNode;  // Link old tail to new node
    }

    // Step 4: Update the tail pointer to the new node (last node)
    tail = newNode;
}

// ============================================================================
//  FUNCTION: print
//  ---------------
//  Purpose:
//      Prints all elements of the Linked List sequentially.
//
//  Parameter:
//      Node* head : Pointer to the first node of the list
//
//  Logic:
//      1️⃣ Use a temporary pointer to traverse the list
//      2️⃣ Print each node’s data until we reach NULL
// ============================================================================
void print(Node* head) {
    Node* temp = head; // Temporary pointer for traversal

    // Traverse until the end of the list
    while (temp != NULL) {
        cout << temp->data << " ";  // Print the current node's data
        temp = temp->next;          // Move to the next node
    }

    cout << endl; // Print newline at the end for formatting
}

// ============================================================================
//  FUNCTION: main
//  --------------
//  Purpose:
//      Demonstrates Linked List operations:
//      → Insertion at head
//      → Insertion at tail
//      → Printing the list
// ============================================================================
int main() {
    Node* head = NULL;  // Initially, the list is empty (no head)
    Node* tail = NULL;  // Tail also points to NULL initially

    // Inserting nodes at the head (new nodes appear at the beginning)
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);

    // Inserting a node at the tail (added at the end of the list)
    insertAtTail(head, tail, 77);

    // Display all nodes of the linked list
    cout << "Printing the Linked List:" << endl;
    print(head);

    return 0;  // End of program
}
