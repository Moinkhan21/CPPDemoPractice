#include <iostream>
using namespace std;

// ===============================
// ✅ Node class definition
// Represents a single node in a linked list
// Each node contains data and a pointer to the next node
// ===============================
class Node {
    public:
    int data;       // Stores the data value of the node
    Node* next;     // Pointer to the next node in the linked list

    // ✅ Constructor to initialize node with given data
    Node(int data) {
        this -> data = data;   // Assign value to the node
        this -> next = NULL;   // Initialize next pointer as NULL
    }
};

// ===============================
// ✅ Function to detect a loop in a linked list
// This uses Floyd’s Cycle Detection Algorithm (also known as Tortoise and Hare algorithm)
// - Slow pointer moves one step at a time
// - Fast pointer moves two steps at a time
// If they meet, it means a loop exists
// ===============================
bool checkForLoop(Node* &head) {
    // ✅ Step 1: Check if list is empty
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return false;  // No loop possible in an empty list
    }

    // ✅ Step 2: Initialize two pointers
    Node* slow = head;  // Moves 1 step each iteration
    Node* fast = head;  // Moves 2 steps each iteration

    // ✅ Step 3: Traverse the linked list
    while(fast != NULL) {   // Continue until fast reaches the end
        fast = fast -> next;  // Move fast one step
        if(fast != NULL) {
            fast = fast -> next;  // Move fast one more step (total 2 steps)
            slow = slow -> next;  // Move slow one step
        }

        // ✅ Step 4: If slow and fast meet, a loop exists
        if(slow == fast) {
            //Loop present
            return true;
        }
    }

    // ✅ Step 5: If loop ends, no loop is found
    //fast NULL hogya
    return false;
}

// ===============================
// ✅ Main function: Entry point of the program
// Creates a linked list manually and checks if a loop is present
// ===============================
int main() {
    // ✅ Step 1: Create nodes dynamically
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    // ✅ Step 2: Link the nodes together to form a linear linked list
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eighth;
    eighth -> next = ninth;

    // ✅ Step 3: Create a loop in the linked list
    // Here, the 9th node points back to the 5th node — forming a loop
    ninth -> next = fifth;
    //ninth -> next = NULL; // Uncomment this line and comment the above one to remove the loop

    // ✅ Step 4: Detect loop presence
    cout << "Loop is present or not " << checkForLoop(head);
    
    return 0;
}
