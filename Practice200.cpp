#include <iostream>
using namespace std;

// Node structure definition
class Node {
public:
    int data;
    Node* next;

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

// Function to insert a node at the head
// Pass head by reference (&) so that the original head gets updated
// I want to insert a node right at the head of Linked List
void insertAtHead(Node*& head, Node* &tail, int data) {
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Point the new node's next to current head
    newNode->next = head;

    // Step 3: Move head to point to new node
    // first Node
    if(head == NULL) {
        tail = newNode;
    }
    head = newNode;
}

//I want to insert a node right at the end of Linked List
void insertAtTail(Node* head, Node* &tail, int data) {
    //Step 1: create a node
    Node* newNode = new Node(data);

    //Step 2: connect with tail node
    if(tail == NULL) {
        tail = newNode;
        head = newNode;
    }
    else{
        tail -> next = newNode;
    }
    tail -> next = newNode;

    //step 3: update tail;
    
    tail = newNode;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;  // Empty list

    Node* tail = NULL; 
    // Insert nodes at the head
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    cout << "Printing the Linked List:" << endl;
    print(head);

    return 0;
}
