#include <iostream>
using namespace std;

// Define the Node class representing a single element in a Doubly Linked List
class Node {
    public:
    int data;       // Stores the data value of the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Default constructor (called when no data is passed)
    Node() {
        this -> data = 0;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // Parameterized constructor (called when a data value is provided)
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // Destructor - gets called automatically when a node is deleted
    ~Node() {
        cout << "Node with value: " << this -> data << " deleted" << endl;
    }
};

// Function to print all nodes of the linked list from head to tail
void print(Node* &head) {
    Node* temp = head;  // Temporary pointer to traverse the list

    while(temp != NULL) {  // Traverse until the end of the list
        cout << temp -> data << " ";  // Print current node's data
        temp = temp -> next;          // Move to the next node
    }
}

// Function to calculate the total number of nodes in the linked list
int getLength(Node* head) {
    int len = 0;          // Counter for node count
    Node* temp = head;    // Temporary pointer for traversal

    while(temp != NULL) { // Traverse till end
        temp = temp -> next;  // Move to next node
        len++;                // Increment count
    }
    return len;               // Return total count
}

// Function to insert a new node at the head (beginning) of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        // LL is empty
        Node* newNode = new Node(data); // Create new node
        head = newNode;                 // Both head and tail point to newNode
        tail = newNode;
        return;
    }

    // LL is non-empty
    // Step 1 : create a node
    Node* newNode = new Node(data);

    // Step 2 : connect newNode's next to current head
    newNode -> next = head;

    // Step 3 : connect current head's prev to newNode
    head -> prev = newNode;

    // Step 4 : update head to point to newNode
    head = newNode;
}

// Function to insert a new node at the tail (end) of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is not empty
    // Step 1 : create a node
    Node* newNode = new Node(data);

    // Step 2 : connect tail's next to newNode
    tail -> next = newNode;

    // Step 3 : connect newNode's prev to tail
    newNode -> prev = tail;

    // Step 4 : move tail to the newNode
    tail = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    if(head == NULL) {
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is not empty
    if(position == 1) {
        // Insert at the beginning
        insertAtHead(head, tail, data);
        return;
    }

    // Find total length to handle tail insertion
    int len = getLength(head);
    if(position > len) {
        // Insert at the end if position > length
        insertAtTail(head, tail, data);
        return;
    }

    // Insertion in the middle
    // Step 1 : find prev && curr
    int i = 1;
    Node* prevNode = head;
    while(i < position - 1) { // Move till node before the insertion point
        prevNode = prevNode -> next;
        i++;
    }
    Node* curr = prevNode -> next; // Current node after which insertion happens

    // Step 2 : create a node
    Node* newNode = new Node(data);

    // Step 3 : connect prevNode to newNode
    prevNode -> next = newNode;

    // Step 4 : connect newNode’s prev to prevNode
    newNode -> prev = prevNode;

    // Step 5 : connect curr’s prev to newNode
    curr -> prev = newNode;

    // Step 6 : connect newNode’s next to curr
    newNode -> next = curr;
}

// Function to delete a node from a given position
void deleteFromPos(Node* &head, Node* &tail, int position) {
    if(head == NULL) {
        cout << "Linked list is empty";
        return;
    }

    if(head -> next == NULL) {
        // Single node in LL
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp; // Delete the only node
        return;
    }

    int len = getLength(head); // Get total nodes

    if(position > len) {
        // Invalid position
        cout << "Please enter valid position" << endl;
        return;
    }

    if(position == 1) {
        // Delete the first node
        Node* temp = head;           // Store current head
        head = head -> next;         // Move head to next node
        head -> prev = NULL;         // Remove backward link
        temp -> next = NULL;         // Break forward link
        delete temp;                 // Delete old head
        return;
    }

    if(position == len) {
        // Delete last node
        Node* temp = tail;           // Store current tail
        tail = tail -> prev;         // Move tail backward
        temp -> prev = NULL;         // Break backward link
        tail -> next = NULL;         // Break forward link
        delete temp;                 // Delete old tail
        return;
    }

    // Delete from middle of linked list
    // Step 1 : find the left, current, and right nodes
    int i = 1;
    Node* left = head;
    while(i < position - 1) {       // Move left pointer to (position-1)
        left = left -> next;
        i++;
    }
    Node* curr = left -> next;      // Current node to delete
    Node* right = curr -> next;     // Node after current

    // Step 2 : connect left to right (skip current)
    left -> next = right;

    // Step 3 : connect right to left
    right -> prev = left;

    // Step 4 : disconnect current node completely
    curr -> next = NULL;
    curr -> prev = NULL;

    delete curr; // Delete current node
}

// Main function - program execution starts here
int main() {
     
    // Step 1: Create three nodes manually
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Step 2: Create head and tail pointers
    Node* head = first;
    Node* tail = third;

    // Step 3: Connect nodes together
    first -> next = second;
    second -> prev = first;

    second -> next = third;
    third -> prev = second;

    // Print initial list
    print(first);
    cout << endl;

    // Insert new node at head
    insertAtHead(head, tail, 101);
    cout << endl;
    print(head);
    cout << endl;

    // Insert new node at tail
    insertAtTail(head, tail, 501);
    cout << endl;
    print(head);
    cout << endl;

    // Insert new node at position 2
    insertAtPosition(head, tail, 401, 2);
    cout << endl;
    print(head);
    cout << endl;

    // Delete node at position 6
    deleteFromPos(head, tail, 6);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}
