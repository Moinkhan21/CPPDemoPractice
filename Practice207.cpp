#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a singly linked list.
//
// Each node contains:
//   • data → integer value
//   • next → pointer to next node
//
// Destructor is used to track memory deallocation.
// ======================================================================
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Node with data " << this->data << " deleted\n";
    }
};

// ======================================================================
// FUNCTION: insertAtHead()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a node at the beginning of the linked list.
//
// EDGE CASE:
//   If list is empty → initialize head and tail
// ======================================================================
void insertAtHead(Node*& head, Node*& tail, int data) {

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// ======================================================================
// FUNCTION: insertAtTail()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a node at the end of the linked list.
// ======================================================================
void insertAtTail(Node*& head, Node*& tail, int data) {

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// ======================================================================
// FUNCTION: findLength()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns the length of the linked list.
//
// TIME COMPLEXITY: O(N)
// ======================================================================
int findLength(Node* head) {

    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len;
}

// ======================================================================
// FUNCTION: insertAtPosition()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a node at a given position.
//
// RULES:
//   • position = 0 → insert at head
//   • position >= length → insert at tail
// ======================================================================
void insertAtPosition(Node*& head, Node*& tail, int data, int position) {

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    // Insert at head
    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    // Insert at tail
    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in middle
    Node* prev = head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }

    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

// ======================================================================
// FUNCTION: deleteNode()
// ----------------------------------------------------------------------
// PURPOSE:
//   Deletes a node from a given position (1-based index).
//
// CASES:
//   1. Delete head
//   2. Delete tail
//   3. Delete middle node
// ======================================================================
void deleteNode(int position, Node*& head, Node*& tail) {

    // Edge case
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Case 1: Delete head
    if (position == 1) {
        Node* temp = head;
        head = head->next;

        if (head == NULL) // if list becomes empty
            tail = NULL;

        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    // Case 2: Delete tail
    if (position >= len) {

        Node* prev = head;
        for (int i = 1; i < len - 1; i++) {
            prev = prev->next;
        }

        Node* temp = tail;
        prev->next = NULL;
        tail = prev;

        delete temp;
        return;
    }

    // Case 3: Delete middle node
    Node* prev = head;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
    }

    Node* curr = prev->next;
    prev->next = curr->next;

    curr->next = NULL;
    delete curr;
}

// ======================================================================
// FUNCTION: print()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the linked list.
// ======================================================================
void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    // Insert operations
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtPosition(head, tail, 15, 1);

    cout << "Linked List:\n";
    print(head);

    // Delete operation
    cout << "\nAfter deleting position 1:\n";
    deleteNode(1, head, tail);
    print(head);

    return 0;
}