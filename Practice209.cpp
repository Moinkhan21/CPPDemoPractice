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
    // Called when a node is created without passing any value
    // ===============================
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // ===============================
    // ✅ Parameterized constructor
    // Called when a node is created with a specific data value
    // ===============================
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // ===============================
    // ✅ Destructor
    // Called automatically when a node is deleted using 'delete'
    // Used here to show which node is being destroyed
    // ===============================
    ~Node() {
        cout << "Node with value: " << this -> data << " Deleted" << endl;
    }
};

// ===================================================================
// ✅ Function: insertAtHead()
// Inserts a new node at the beginning of the Linked List.
// We pass head & tail by reference (&) so the original pointers update.
// ===================================================================
void insertAtHead(Node*& head, Node*& tail, int data) {

    // Case 1: Empty Linked List → New node becomes both head and tail
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
  
    // Step 1: Create a new node with given data
    Node* newNode = new Node(data);

    // Step 2: Connect new node's next to the current head node
    newNode->next = head;

    // Step 3: Update head pointer to point to the new node
    head = newNode;
}

// ===================================================================
// ✅ Function: insertAtTail()
// Inserts a new node at the end of the Linked List.
// ===================================================================
void insertAtTail(Node* head, Node*& tail, int data) {

    // Case 1: If Linked List is empty
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Connect tail's next pointer to the new node
    tail -> next = newNode;

    // Step 3: Update tail pointer to point to the new node
    tail = newNode;
}

// ===================================================================
// ✅ Function: print()
// Traverses and prints all nodes in the Linked List.
// ===================================================================
void print(Node* head) {
    Node* temp = head;

    // Traverse until the end (NULL)
    while (temp != NULL) {
        cout << temp->data << " ";  // Print each node's data
        temp = temp->next;          // Move to next node
    }
    cout << endl;
}

// ===================================================================
// ✅ Function: findLength()
// Counts and returns the total number of nodes in the Linked List.
// ===================================================================
int findLength(Node*& head) {
    int len = 0;            // Counter for nodes
    Node* temp = head;      // Start from head

    while(temp != NULL) {   // Traverse until end
        temp = temp -> next;
        len++;
    }
    return len;             // Return total count
}

// ===================================================================
// ✅ Function: insertAtPosition()
// Inserts a new node at a specific position in the Linked List.
// ===================================================================
void insertAtPosition(int data, int position, Node*& head, Node*& tail) {

    // Case 1: Empty Linked List → Insert the first node
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Case 2: Insert at the beginning (position 0)
    if(position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    // Case 3: Insert at or beyond the end
    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Case 4: Insert somewhere in the middle
    // Step 1: Traverse to the node just before insertion point
    int i = 1;
    Node* prev = head;
    while(i < position) {
        prev = prev -> next;
        i++;
    }

    // 'prev' points to (position-1)th node
    Node* curr = prev -> next; // Current node after the insertion point

    // Step 2: Create a new node
    Node* newNode = new Node(data);

    // Step 3: Connect newNode's next to current node
    newNode -> next = curr;

    // Step 4: Connect previous node to newNode
    prev -> next = newNode;
}

// ===================================================================
// ✅ Function: deleteNode()
// Deletes a node from a given position (1-based index).
// ===================================================================
void deleteNode(int position, Node*& head, Node*& tail) {

    // Case 1: Linked List is empty
    if(head == NULL) {
        cout << "Cannot delete, LL is empty";
        return;
    }

    // Case 2: Deleting the first node
    if(position == 1) {
        Node* temp = head;          // Store current head
        head = head -> next;        // Move head to next node
        temp -> next = NULL;        // Disconnect old head
        delete temp;                // Delete node safely
        return;
    }

    int len = findLength(head);     // Find length to handle tail deletion

    // Case 3: Deleting the last node
    if(position == len) {

        // Step 1: Traverse to the node before tail
        int i = 1;
        Node* prev = head;
        while(i < position - 1) {
            prev = prev -> next;
            i++;
        }

        // Step 2: Disconnect last node from previous
        prev -> next = NULL;

        // Step 3: Store tail node temporarily
        Node* temp = tail;

        // Step 4: Update tail to new last node
        tail = prev;

        // Step 5: Delete old tail node
        delete temp;

        return;
    }

    // Case 4: Deleting a middle node
    // Step 1: Find previous and current node
    int i = 1;
    Node* prev = head;
    while(i < position - 1){
        prev = prev -> next;
        i++;
    }
    Node* curr = prev -> next;   // Node to delete

    // Step 2: Connect previous node to node after current
    prev -> next = curr -> next;

    // Step 3: Disconnect current node from list
    curr -> next = NULL;

    // Step 4: Delete current node
    delete curr;
}

// ===================================================================
// ✅ main() - Program execution starts here
// Demonstrates insertion and deletion in a Singly Linked List
// ===================================================================
int main() {
    Node* head = NULL;  // Start with an empty list
    Node* tail = NULL;  // Initially, no tail

    // =========================
    // Inserting nodes at head
    // =========================
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);

    // Insert a node at tail
    insertAtTail(head, tail, 77);

    cout << "Printing the Linked List:" << endl;
    print(head);

    cout << endl;
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    // Insert node at a specific position
    insertAtPosition(101, 6, head, tail);
    cout << endl;
    print(head);

    cout << endl;
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    // Delete node from position 3
    deleteNode(3, head, tail);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}
