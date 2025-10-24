#include <iostream>
using namespace std;

// ===============================
// ✅ Node structure definition
// ===============================
class Node {
public:
    int data;       // Stores value of the node
    Node* next;     // Pointer to the next node in the linked list

    // ===============================
    // ✅ Default constructor
    // ===============================
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // ===============================
    // ✅ Parameterized constructor
    // ===============================
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // ===============================
    // ✅ Destructor
    // ===============================
    ~Node() {
        cout << "Node with value: " << this->data << " Deleted" << endl;
    }
};

// ===================================================================
// ✅ Function: insertAtHead()
// Inserts a new node at the beginning of the Circular Linked List.
// ===================================================================
void insertAtHead(Node*& head, Node*& tail, int data) {

    // Case 1: Empty Circular Linked List
    if (tail == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;   // Make it circular
        return;
    }

    // Step 1: Create new node
    Node* newNode = new Node(data);

    // Step 2: Link new node to current head
    newNode->next = head;

    // Step 3: Move head to new node
    head = newNode;

    // Step 4: Maintain circular connection
    tail->next = head;
}

// ===================================================================
// ✅ Function: insertAtTail()
// Inserts a new node at the end of the Circular Linked List.
// ===================================================================
void insertAtTail(Node*& head, Node*& tail, int data) {

    // Case 1: Empty List
    if (tail == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;   // Circular connection
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Connect current tail to new node
    tail->next = newNode;

    // Step 3: Update tail to new node
    tail = newNode;

    // Step 4: Maintain circular connection
    tail->next = head;
}

// ===================================================================
// ✅ Function: print()
// Traverses and prints all nodes in the Circular Linked List.
// ===================================================================
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    // Traverse until we come back to head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// ===================================================================
// ✅ Function: findLength()
// Counts and returns the total number of nodes in the Circular Linked List.
// ===================================================================
int findLength(Node*& head) {
    if (head == NULL)
        return 0;

    int len = 0;
    Node* temp = head;

    do {
        len++;
        temp = temp->next;
    } while (temp != head);

    return len;
}

// ===================================================================
// ✅ Function: insertAtPosition()
// Inserts a new node at a specific position in the Circular Linked List.
// ===================================================================
void insertAtPosition(int data, int position, Node*& head, Node*& tail) {

    // Case 1: Empty List
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;   // Circular connection
        return;
    }

    // Case 2: Insert at beginning
    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    // Case 3: Insert at or beyond the end
    int len = findLength(head);
    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Case 4: Insert in the middle
    int i = 1;
    Node* prev = head;
    while (i < position) {
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;
    Node* newNode = new Node(data);

    newNode->next = curr;
    prev->next = newNode;
}

// ===================================================================
// ✅ Function: deleteNode()
// Deletes a node from a given position (1-based index).
// ===================================================================
void deleteNode(int position, Node*& head, Node*& tail) {

    // Case 1: Empty list
    if (head == NULL) {
        cout << "Cannot delete, list is empty!" << endl;
        return;
    }

    int len = findLength(head);

    // Case 2: Deleting the first node
    if (position == 1) {
        Node* temp = head;

        // Single node case
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        }

        head = head->next;
        tail->next = head; // Maintain circular connection
        temp->next = NULL;
        delete temp;
        return;
    }

    // Case 3: Deleting the last node
    if (position == len) {
        int i = 1;
        Node* prev = head;

        while (i < position - 1) {
            prev = prev->next;
            i++;
        }

        Node* temp = tail;
        prev->next = head; // Maintain circular connection
        tail = prev;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Case 4: Deleting from middle
    int i = 1;
    Node* prev = head;
    while (i < position - 1) {
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// ===================================================================
// ✅ main() - Demonstration of Circular Singly Linked List
// ===================================================================
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting nodes
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);

    insertAtTail(head, tail, 77);

    cout << "Printing the Circular Linked List:" << endl;
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    // Insert node at specific position
    insertAtPosition(101, 6, head, tail);
    cout << "\nAfter insertion at position 6:" << endl;
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    // Delete node from position 3
    deleteNode(3, head, tail);
    cout << "\nAfter deleting position 3:" << endl;
    print(head);

    cout << endl;
    return 0;
}
