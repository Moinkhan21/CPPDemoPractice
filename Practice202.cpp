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

    //ToDo: Write a destructor to delete a node
    ~Node() {
        //Write your code here
        cout << "Node with value: " << this -> data << " Deleted" << endl;
    }
};

// Function to insert a node at the head
// Pass head by reference (&) so that the original head gets updated
// I want to insert a node right at the head of Linked List
void insertAtHead(Node*& head, Node* &tail, int data) {

    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
  
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Point the new node's next to current head
    newNode->next = head;

    // Step 3: Move head to point to new node
    head = newNode;
}

//I want to insert a node right at the end of Linked List
void insertAtTail(Node* head, Node* &tail, int data) {

    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }

    //Step 1: create a node
    Node* newNode = new Node(data);

    //Step 2: connect with tail node 
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

int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //Handling Head and tail
    if(position == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    //Step1: Fint the positon: prev & curr 
    int i = 1;
    Node* prev = head;
    while(i < position) {
        prev = prev -> next;
        i++;
    }
    Node* curr = prev -> next;

    //Step2:
    Node* newNode = new Node(data);

    //Step3:
    newNode -> next = curr;

    //Step4:
    prev -> next = newNode;

}

void deleteNode(int position, Node* &head, Node* &tail) {
    if(head == NULL) {
        cout << "Cannot delete, LL is empty";
        return;
    }

    //Deleting first node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    //Deleting last node
    if(position == len) {

        //Find prev
        int i = 1;
        Node* prev = head;
        while(i < position - 1) {
            prev = prev -> next;
            i++;
        }

        //Step 2:
        prev -> next = NULL;

        //Step 3:
        Node* temp = tail;

        //Step 4:
        tail = prev;

        //Step 5;
        delete temp;

        return;
    }

    //Deleting middle node

    //Step : find prev and curr
    int i = 1;
    Node* prev = head;
    while(i < position - 1){
        prev = prev -> next;
        i++;
    }
    Node* curr = prev -> next;

    //Step 2:
    prev -> next = curr -> next;

    //Step 3:
    curr -> next = NULL;

    //Step 4:
    delete curr;
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

    cout << endl;
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    insertAtPosition(101, 6, head, tail);
    cout << endl;
    print(head);

    cout << endl;
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    deleteNode(3, head, tail);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}
