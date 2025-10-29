#include <iostream>
using namespace std;

// ==============================================
// ✅ Node class definition
// Represents a single node of a singly linked list.
// Each node stores an integer 'data' and a pointer 'next'
// to the next node in the list.
// ==============================================
class Node {
    public:
        int data;    // Stores the data value of the node
        Node* next;  // Pointer to the next node

        // Constructor initializes the node with data
        // and sets 'next' pointer to NULL.
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

// ==============================================
// ✅ Function: print()
// Purpose: Prints the elements of the linked list
// starting from the head node till the end (NULL).
// ==============================================
void print(Node* head) {
    Node* temp = head;   // Temporary pointer to traverse the list

    // Traverse until we reach the end (NULL)
    while (temp != NULL) {
        cout << temp -> data << " ";   // Print current node data
        temp = temp -> next;           // Move to next node
    }
    cout << endl;   // Print newline after list output
}

// ==============================================
// ✅ Function: removeDuplicates()
// Purpose: Removes duplicate nodes from a sorted linked list.
// Logic:
//   - Since the linked list is sorted, duplicates
//     will appear next to each other.
//   - Traverse the list, and if the current node
//     has the same data as the next node, remove the next node.
// ==============================================
void removeDuplicates(Node* &head) {

    // Case 1: If the list is empty
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }

    // Case 2: If there is only one node
    if(head -> next == NULL) {
        cout << "Single Node in LL " << endl;
        return;
    }

    // Case 3: If the list has more than one node
    Node* curr = head;   // Start from the head node

    // Traverse the linked list until the end
    while(curr != NULL) {

        // Check if the next node exists and has the same value
        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)) {

            // Equal values found → duplicate node detected

            Node* temp = curr -> next;        // Store the duplicate node
            curr -> next = curr -> next -> next;  // Skip the duplicate node

            // Delete the duplicate node safely
            temp -> next = NULL;
            delete temp;
        }
        else {
            // Not equal → move to the next node
            curr = curr -> next;
        }
    }
}

// ==============================================
// ✅ main()
// Creates a sorted linked list with duplicates,
// removes the duplicates, and prints the result.
// ==============================================
int main() {
    // Creating linked list nodes manually
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(4);
    Node* sixth = new Node(4);

    // Linking nodes together
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;

    // Print original linked list
    cout << "Input LL : ";
    print(head);

    // Remove duplicate nodes
    removeDuplicates(head);

    // Print final list after removing duplicates
    cout << "Output LL : ";
    print(head);

    return 0;
}
