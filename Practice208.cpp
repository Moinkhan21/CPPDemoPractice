#include <iostream>
using namespace std;

// Define the Node class representing a single element in a Circular Doubly Linked List
class Node {
public:
    int data;       // Stores the data value of the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Default constructor
    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    // Parameterized constructor
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor - gets called automatically when a node is deleted
    ~Node() {
        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

// Function to print all nodes of the circular linked list (stops when back to head)
void print(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);  // Stop when we come back to the head
}

// Function to calculate the total number of nodes in the circular linked list
int getLength(Node* head) {
    if (head == NULL) return 0;

    int len = 0;
    Node* temp = head;
    do {
        len++;
        temp = temp->next;
    } while (temp != head);
    return len;
}

// Function to insert a new node at the head (beginning) of the circular doubly linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        // Empty list
        Node* newNode = new Node(data);
        head = tail = newNode;
        tail->next = head;  // Make it circular
        head->prev = tail;
        return;
    }

    // Non-empty list
    Node* newNode = new Node(data);
    newNode->next = head;   // Step 1: link newNode to current head
    head->prev = newNode;   // Step 2: link current head back to newNode
    head = newNode;         // Step 3: move head to newNode
    tail->next = head;      // Step 4: maintain circular connection
    head->prev = tail;
}

// Function to insert a new node at the tail (end) of the circular doubly linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        tail->next = head;
        head->prev = tail;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;   // Step 1: tail’s next points to newNode
    newNode->prev = tail;   // Step 2: newNode’s prev points to old tail
    tail = newNode;         // Step 3: move tail to newNode
    tail->next = head;      // Step 4: circular link from tail to head
    head->prev = tail;
}

// Function to insert a node at a specific position
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        tail->next = head;
        head->prev = tail;
        return;
    }

    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);
    if (position > len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Insertion in the middle
    int i = 1;
    Node* prevNode = head;
    while (i < position - 1) {
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode->next;
    Node* newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;
}

// Function to delete a node from a given position
void deleteFromPos(Node* &head, Node* &tail, int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    int len = getLength(head);

    if (position > len) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (len == 1) {
        Node* temp = head;
        head = tail = NULL;
        delete temp;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        temp->next = temp->prev = NULL;
        delete temp;
        return;
    }

    if (position == len) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        temp->next = temp->prev = NULL;
        delete temp;
        return;
    }

    // Deleting from middle
    int i = 1;
    Node* left = head;
    while (i < position - 1) {
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;

    curr->next = curr->prev = NULL;
    delete curr;
}

// Main function
int main() {
    // Step 1: Create three nodes manually
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Step 2: Create head and tail pointers
    Node* head = first;
    Node* tail = third;

    // Step 3: Connect nodes together (circular doubly)
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    // Step 4: Make it circular
    tail->next = head;
    head->prev = tail;

    // Print initial list
    print(head);
    cout << endl;

    // Insert new node at head
    insertAtHead(head, tail, 101);
    print(head);
    cout << endl;

    // Insert new node at tail
    insertAtTail(head, tail, 501);
    print(head);
    cout << endl;

    // Insert new node at position 3
    insertAtPosition(head, tail, 401, 3);
    print(head);
    cout << endl;

    // Delete node at position 2
    deleteFromPos(head, tail, 2);
    print(head);
    cout << endl;

    return 0;
}
