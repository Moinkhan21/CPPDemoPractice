#include <iostream>
using namespace std;

// ===============================
// ✅ Node class definition
// Represents each element (node) in the linked list
// Each node contains an integer value (data) and a pointer to the next node
// ===============================
class Node {

    public:
    int data;   // Stores the data value of the node
    Node* next; // Pointer to the next node in the linked list

    // ✅ Constructor to initialize node with a value
    Node(int data) {
        this -> data = data;
        this -> next = NULL;  // Initialize next as NULL by default
    }
};

// ===============================
// ✅ Function to print the linked list
// Traverses from head to NULL and prints all node values
// ===============================
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

// ===============================
// ✅ Function to detect if a loop exists in the linked list
// Uses Floyd’s Cycle Detection Algorithm (Tortoise & Hare algorithm)
// Logic:
//   - Move `slow` pointer by 1 step
//   - Move `fast` pointer by 2 steps
//   - If they ever meet, there is a loop
// ===============================
bool checkForLoop(Node* &head) {
    // ✅ Step 1: Check for empty list
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return false;
    }

    Node* slow = head;  // Moves one step at a time
    Node* fast = head;  // Moves two steps at a time

    // ✅ Step 2: Traverse the list to check for loop
    while(fast != NULL) {
        fast = fast -> next;  // Move fast by one step first

        if(fast != NULL) {    // Ensure fast is not NULL before accessing next
            fast = fast -> next;  // Move fast by another step (total 2 steps)
            slow = slow -> next;  // Move slow by one step
        }

        // ✅ Step 3: If both meet, loop detected
        if(slow == fast) {
            //Loop present
            return true;
        }
    }

    // ✅ Step 4: If fast becomes NULL, no loop found
    //fast NULL hogya
    return false;
}

// ===============================
// ✅ Function to find the starting node of a loop in the linked list
// Steps:
// 1️⃣ Use Floyd’s algorithm to detect if a loop exists
// 2️⃣ When slow == fast, reset `slow` to head
// 3️⃣ Move both pointers one step at a time
// 4️⃣ The node where they meet again is the starting point of the loop
// ===============================
Node* startingPointLoop(Node* &head) {
    // ✅ Step 1: Handle empty list case
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    // ✅ Step 2: Detect if loop exists
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        // ✅ Step 3: If loop detected, move slow to head
        if(slow == fast) {
            slow = head;
            break;
        }
    }
    
    // ✅ Step 4: Move both one step at a time until they meet
    // That meeting point is the starting node of the loop
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return fast;  // or return slow (both point to the same node)
}

// ===============================
// ✅ Main function
// Creates a linked list, introduces a loop, and detects it
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

    // ✅ Step 2: Connect the nodes to form a linked list
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eighth;
    eighth -> next = ninth;

    // ✅ Step 3: Introduce a loop manually
    // ninth -> next points back to fifth, forming a cycle
    ninth -> next = fifth;
    //ninth -> next = NULL; // Uncomment this line to remove the loop

    // ✅ Step 4: Check whether a loop is present
    cout << "Loop is present or not " << checkForLoop(head) << endl;

    // ✅ Step 5: Find and print the starting node of the loop
    cout << "Starting point of LOOP is: " << startingPointLoop(head) -> data << endl;
    
    return 0;
}
