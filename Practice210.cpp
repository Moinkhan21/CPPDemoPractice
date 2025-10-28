#include <iostream>
using namespace std;

// =======================================
// ✅ Node Class Definition
// Represents a single node in a Singly Linked List
// Each node contains 'data' and a pointer 'next' to the next node
// =======================================
class Node {
public:
    int data;   // Data part of the node
    Node* next; // Pointer to the next node in the list

    // ---------------------------------------
    // Constructor: initializes data and sets next pointer to NULL
    // ---------------------------------------
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// =======================================
// ✅ Function: print()
// Prints the complete linked list from head to end
// =======================================
void print(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list

    // Traverse until the end of the list (NULL)
    while (temp != NULL) {
        cout << temp->data << "->"; // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl; // End the line after printing the full list
}

// =======================================
// ✅ Function: getMiddle()
// Finds the middle node of a singly linked list using
// the two-pointer technique (slow and fast pointer method)
// =======================================
Node* getMiddle(Node*& head) {
    // -------------------------------
    // Edge Case 1: If the linked list is empty
    // -------------------------------
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return head; // Return NULL
    }

    // -------------------------------
    // Edge Case 2: If there is only one node
    // -------------------------------
    if (head->next == NULL) {
        // Only one node, so that itself is the middle
        return head;
    }

    // -------------------------------
    // Case 3: Linked list has more than one node
    // Use two pointers: 'slow' and 'fast'
    // 'slow' moves one step at a time
    // 'fast' moves two steps at a time
    // When 'fast' reaches the end, 'slow' will be at the middle
    // -------------------------------
    Node* slow = head;
    Node* fast = head;

    // Traverse until the fast pointer reaches the end
    while (slow != NULL && fast != NULL) {
        // Move fast pointer one step
        fast = fast->next;

        // Check if fast can move one more step
        if (fast != NULL) {
            // Move fast by one more step (total two steps)
            fast = fast->next;

            // Move slow by one step
            slow = slow->next;
        }
    }

    // When loop ends, 'slow' will point to the middle node
    return slow;
}

// =======================================
// ✅ main() Function
// Creates a Linked List, prints it, and displays the middle node
// =======================================
int main() {
    // ---------------------------------------
    // Step 1: Create nodes dynamically
    // ---------------------------------------
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    // ---------------------------------------
    // Step 2: Link all nodes together
    // head → second → third → fourth → fifth → NULL
    // ---------------------------------------
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    // ---------------------------------------
    // Step 3: Print the Linked List
    // ---------------------------------------
    cout << "Linked List: ";
    print(head);

    cout << endl;

    // ---------------------------------------
    // Step 4: Find and print the middle node's data
    // ---------------------------------------
    cout << "Middle Node is: " << getMiddle(head)->data << endl;

    return 0;
}
