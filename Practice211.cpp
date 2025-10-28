#include <iostream>
using namespace std;

// =======================================
// ✅ Node Class Definition
// Represents a single node in the singly linked list
// Each node stores some data and a pointer to the next node
// =======================================
class Node {

public:
    int data;     // Stores the value of the node
    Node* next;   // Pointer that points to the next node in the list

    // ---------------------------------------
    // ✅ Constructor: Initializes a new node with given data
    // ---------------------------------------
    Node(int data) {
        this->data = data;   // Assign the data
        this->next = NULL;   // Initialize next pointer as NULL
    }
};

// =======================================
// ✅ Function: print()
// Prints the complete linked list starting from the head node
// =======================================
void print(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list

    // Traverse until reaching the end (NULL)
    while (temp != NULL) {
        cout << temp->data << "->";  // Print the current node’s data
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl;          // Indicate the end of the list
}

// =======================================
// ✅ Function: getMiddle()
// Finds and returns the middle node of a linked list
// Uses the "Fast and Slow Pointer" technique
// =======================================
Node* getMiddle(Node*& head) {
    // -------------------------------
    // 🔹 Edge Case 1: Empty linked list
    // -------------------------------
    if (head == NULL) {
        cout << "Linked List is empty!" << endl;
        return head;
    }

    // -------------------------------
    // 🔹 Edge Case 2: Only one node in the list
    // -------------------------------
    if (head->next == NULL) {
        // The only node itself is the middle
        return head;
    }

    // -------------------------------
    // 🔹 Case 3: More than one node
    // Initialize two pointers:
    // slow → moves 1 step at a time
    // fast → moves 2 steps at a time
    // -------------------------------
    Node* slow = head;       // Starts at head
    Node* fast = head->next; // Starts one step ahead

    // Traverse the list until fast reaches the end
    while (slow != NULL && fast != NULL) {
        fast = fast->next; // Move fast by one step first

        // If fast is not NULL, move it one more step
        if (fast != NULL) {
            fast = fast->next;  // Move fast by another step (total 2)
            slow = slow->next;  // Move slow by one step
        }
    }

    // When the loop ends, slow will be pointing to the middle node
    return slow;
}

// =======================================
// ✅ main() Function
// Creates a linked list, prints it, and displays the middle node
// =======================================
int main() {
    // ---------------------------------------
    // Step 1: Create 6 nodes dynamically
    // ---------------------------------------
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    // ---------------------------------------
    // Step 2: Connect all nodes sequentially
    // head → second → third → fourth → fifth → sixth → NULL
    // ---------------------------------------
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    // ---------------------------------------
    // Step 3: Print the linked list
    // ---------------------------------------
    cout << "Linked List: ";
    print(head);

    cout << endl;

    // ---------------------------------------
    // Step 4: Find and display the middle node’s data
    // ---------------------------------------
    cout << "Middle Node is: " << getMiddle(head)->data << endl;

    return 0;
}
