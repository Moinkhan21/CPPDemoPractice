#include <iostream>
using namespace std;

// ============================================================================
// CLASS: Node
// -----------
// A single node of a Singly Linked List.
// Each node stores an integer value (data) and a pointer (next) to the next node.
// ============================================================================
class Node {
public:
    int data;     // Value of the node
    Node* next;   // Pointer to the next node

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
// Purpose:
//     Inserts a new node at the end (tail) of the Linked List.
//
// Parameters:
//     Node*& head → Reference to the head pointer
//     Node*& tail → Reference to the tail pointer
//     int data    → Value to be stored in the new node
// ============================================================================
void insertAtTail(Node*& head, Node*& tail, int data) {

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: If the list is empty (head and tail are NULL)
    if (head == NULL) {
        head = newNode;   // First node becomes head
        tail = newNode;   // First node also becomes tail
        return;
    }

    // Step 3: Link the new node at the end of the list
    tail->next = newNode;

    // Step 4: Move the tail pointer to the new last node
    tail = newNode;
}

// ============================================================================
// FUNCTION: print
// ---------------
// Purpose:
//     Prints the values of all nodes in the Linked List sequentially.
//
// Parameter:
//     Node* head → Pointer to the first node
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
// FUNCTION: reverse
// -----------------
// Purpose:
//     Reverses the Linked List using recursion.
//
// Parameters:
//     Node*& prev → Keeps track of the previous node (used for reversing links)
//     Node*& curr → The current node being processed
//
// Working:
//     1️⃣ Base Case → If curr == NULL, list is completely reversed; return prev.
//     2️⃣ Recursive Case:
//         - Store the next node in a temporary pointer (forward).
//         - Reverse the link: curr->next = prev.
//         - Move one step forward by calling reverse(forward pointers updated).
// ============================================================================
Node* reverse(Node*& prev, Node*& curr) {
    // Base Case: when we reach the end of the list
    if (curr == NULL) {
        // The "prev" pointer now points to the new head (reversed list)
        return prev;
    }

    // Step 1: Store the address of the next node before breaking the link
    Node* forward = curr->next;

    // Step 2: Reverse the link
    curr->next = prev;

    // Step 3: Recursive call
    // Now, move one step ahead:
    // 'curr' becomes 'prev', and 'forward' becomes 'curr'
    return reverse(curr, forward);
}

// ============================================================================
// FUNCTION: main
// --------------
// Demonstrates:
//     1️⃣ Creating a singly linked list
//     2️⃣ Printing it
//     3️⃣ Reversing it using recursion
//     4️⃣ Printing the reversed list
// ============================================================================
int main() {
    Node* head = NULL;  // Initially, list is empty
    Node* tail = NULL;  // Tail pointer for insertion at end

    // Insert elements at the tail
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    // Display original list
    cout << "Original Linked List: ";
    print(head);

    // Initialize prev and curr pointers for reversal
    Node* prev = NULL;
    Node* curr = head;

    // Reverse the Linked List
    head = reverse(prev, curr);

    // Display reversed list
    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
