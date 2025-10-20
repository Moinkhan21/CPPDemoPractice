#include <iostream>
using namespace std;

Node* reverseUsingLoop(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr -> next;
        prev = curr;
        curr = temp;
    }
    return prev;
 }

Node* reverseUsingRecursion(Node* prev, Node* curr) {
    //Base case
    if(curr == NULL) 
        return prev;
    
        Node* temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;

    // Recursion sambhal lega
    return reverseUsingRecursion(prev, curr);

}

int main() {

    Node* prev = NULL;
    Node* curr = head;

    cout << "Printing reverse list" << endl;
    head = reverseUsingLoop(head);
    //head = reverseUsingRecursion(prev, curr); // When calling recursion
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}