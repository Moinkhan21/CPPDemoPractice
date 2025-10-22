#include <iostream>
using namespace std;

// ============================================================================
// CLASS: Node
// -----------
// Represents a single node in a Singly Linked List.
// Each node contains an integer (data) and a pointer to the next node.
// ============================================================================
class Node {
public:
    int data;     // Holds the data of the node
    Node* next;   // Points to the next node in the list

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ============================================================================
// FUNCTION: insertAtTail
// ----------------------
// Inserts a new node at the end (tail) of the linked list.
//
// Parameters:
//   Node*& head → Reference to the head pointer of the list
//   Node*& tail → Reference to the tail pointer of the list
//   int data    → Data to insert
// ============================================================================
void insertAtTail(Node*& head, Node*& tail, int data) {
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: If the list is empty, initialize head and tail
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Link the new node at the end
    tail->next = newNode;

    // Step 4: Update the tail pointer
    tail = newNode;
}

// ============================================================================
// FUNCTION: print
// ---------------
// Prints all the nodes of the linked list sequentially.
//
// Parameter:
//   Node* head → Pointer to the first node in the list
// ============================================================================
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ============================================================================
// FUNCTION: reverseUsingLoop
// --------------------------
// Purpose:
//   Reverses the linked list using an iterative (loop-based) approach.
//
// Parameters:
//   Node* head → Pointer to the first node of the list
//
// Returns:
//   New head pointer after reversal.
//
// Logic:
//   1️⃣ Initialize three pointers: prev (NULL), curr (head), next (NULL).
//   2️⃣ Traverse the list and reverse the links one by one.
//   3️⃣ When curr becomes NULL, prev points to the new head.
// ============================================================================
Node* reverseUsingLoop(Node* head) {
    Node* prev = NULL;   // Previous node pointer
    Node* curr = head;   // Current node pointer

    while (curr != NULL) {
        // Step 1: Temporarily store the next node
        Node* nextNode = curr->next;

        // Step 2: Reverse the link (make current node point to previous)
        curr->next = prev;

        // Step 3: Move both pointers one step ahead
        prev = curr;
        curr = nextNode;
    }

    // After the loop, 'prev' points to the new head
    return prev;
}

// ============================================================================
// FUNCTION: reverseUsingRecursion
// -------------------------------
// Purpose:
//   Reverses the linked list using recursion.
//
// Parameters:
//   Node* prev → Pointer to previous node
//   Node* curr → Pointer to current node
//
// Returns:
//   New head pointer after the entire list is reversed.
//
// Logic:
//   1️⃣ Base Case: If curr == NULL → all links reversed → return prev.
//   2️⃣ Store the next node before breaking the link.
//   3️⃣ Reverse the current node’s pointer to point to previous.
//   4️⃣ Move one step ahead recursively.
// ============================================================================
Node* reverseUsingRecursion(Node* prev, Node* curr) {
    // Base case: when current node is NULL, we reached the end
    if (curr == NULL)
        return prev;

    // Step 1: Save the next node
    Node* nextNode = curr->next;

    // Step 2: Reverse the link
    curr->next = prev;

    // Step 3: Recursive call for the next node
    return reverseUsingRecursion(curr, nextNode);
}

// ============================================================================
// FUNCTION: main
// --------------
// Demonstrates creation, printing, and reversal (loop and recursion)
// of a Singly Linked List.
// ============================================================================
int main() {
    Node* head = NULL;  // Initially, list is empty
    Node* tail = NULL;  // Tail pointer for efficient insertion

    // Inserting data into the linked list
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original Linked List: ";
    print(head);

    // ------------------------------------------------------------------------
    // Reverse using Iterative (Loop) Method
    // ------------------------------------------------------------------------
    head = reverseUsingLoop(head);
    cout << "Reversed Linked List using Loop: ";
    print(head);

    // ------------------------------------------------------------------------
    // Reverse using Recursive Method (to restore original order)
    // ------------------------------------------------------------------------
    Node* prev = NULL;
    Node* curr = head;
    head = reverseUsingRecursion(prev, curr);

    cout << "Reversed Linked List using Recursion: ";
    print(head);

    return 0;
}
