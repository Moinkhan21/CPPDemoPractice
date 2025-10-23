#include <iostream>
using namespace std;


class Node{

    public:
    int data;
    Node* next;
    
    Node() {
        this -> data = 0;
        this -> next = NULL;
    }

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        cout << "Node with data" << this -> data << " Delete" << endl;
    }

};

void insertAtHead(Node*& head, Node*& tail, int data) {
    if(head == NULL) {
    Node* newNode = new Node(data);
    tail = newNode;
    head = newNode;
    return;
 }

 Node* newNode = new Node(data);
 newNode -> next = head;
 head = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    if(head == NULL) {
    Node* newNode = new Node(data);
    tail = newNode;
    head = newNode;
    return;
 }

 Node* newNode = new Node(data);
 tail -> next = newNode;
 tail = newNode;
}

int findLength(Node*& head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtPosition(Node*& head, Node*& tail, int data, int position) {
    if(head == NULL) {
    Node* newNode = new Node(data);
    tail = newNode;
    head = newNode;
    return;
 }

    if(position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node* prev = head;
    while(i < position) {
        prev = prev -> next;
        i++;
    }

    Node* curr = prev -> next;
    Node* newNode = new Node(data);
    newNode -> next = curr;
    prev -> next = newNode;
}

void print(Node*& head) {
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(int position, Node*& head, Node*& tail) {
     if(head == NULL) {
        cout << "There is no linked list or Invalid input" << endl;
     }

     if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
     }

     int len = findLength(head);

     if(position == len) {

        int i = 1;
        Node* prev = head;
        while(i < position - 1){
            prev = prev -> next;
            i++;
        }

        prev -> next = NULL;
        Node* temp = tail;
        tail = prev;
        delete temp;
        return;
     }

     int i = 1;
        Node* prev = head;
        while(i < position - 1){
            prev = prev -> next;
            i++;
        }

        Node* curr = prev -> next;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        return; 
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtPosition(head, tail, 15, 1);

    print(head);
    cout << endl;

    deleteNode(1, head, tail);
    print(head);
}