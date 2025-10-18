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
void insertAtHead(Node*& head, int data) {
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Point the new node's next to current head
    newNode->next = head;

    // Step 3: Move head to point to new node
    head = newNode;
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

    // Insert nodes at the head
    insertAtHead(head, 20);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 90);

    cout << "Printing the Linked List:" << endl;
    print(head);

    return 0;
}
