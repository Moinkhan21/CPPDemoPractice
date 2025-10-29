#include <iostream>
using namespace std;

// =============================================
// ✅ Node class definition for Linked List
// Each node contains 'data' and a pointer 'next'
// =============================================
class Node {
    public:
    int data;      // stores node's value
    Node* next;    // pointer to the next node

    // Constructor — initializes node with given data
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// =============================================
// ✅ Function: print()
// Prints the Linked List until NULL is encountered
// =============================================
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

// =============================================
// ✅ Function: checkForLoop()
// Detects if a loop exists in the linked list using
// Floyd’s Cycle Detection Algorithm (Tortoise-Hare)
// =============================================
bool checkForLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return false;
    }

    Node* slow = head;  // moves 1 step
    Node* fast = head;  // moves 2 steps

    // Continue until fast reaches the end
    while(fast != NULL) {
        fast = fast -> next; // move fast one step

        if(fast != NULL) {   // if possible, move fast one more step
            fast = fast -> next;
            slow = slow -> next; // move slow by one
        }

        if(slow == fast) {
            // ✅ Loop detected
            return true;
        }
    }
    // fast becomes NULL => no loop
    return false;
}

// =============================================
// ✅ Function: startingPointLoop()
// Finds the starting node where the loop begins
// Step 1: Detect intersection using Floyd’s Algorithm
// Step 2: Move 'slow' to head, then move both one step
//         at a time; the meeting point = loop start
// =============================================
Node* startingPointLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd's approach
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast) {
            // When they meet, reset slow to head
            slow = head;
            break;
        }
    }

    // Step 2: Move both pointers one step at a time
    // The meeting point is the start of the loop
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return fast; // or slow — both are same here
}

// =============================================
// ✅ Function: removeLoop()
// Removes the loop from linked list by setting
// the last node of loop's next pointer to NULL
// Steps:
// 1. Detect loop using Floyd’s algorithm
// 2. Find loop start
// 3. Traverse until node before loop start & make next = NULL
// =============================================
Node* removeLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect intersection point
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast) {
            // Loop detected, reset slow to head
            slow = head;
            break;
        }
    }

    // Step 2: Traverse until one node before the starting node of loop
    Node* prev = fast;
    while(slow != fast) {
        prev = fast;
        slow = slow -> next;
        fast = fast -> next;
    }

    // Step 3: Break the loop
    prev -> next = NULL;

    return fast; // Return loop starting node
}

// =============================================
// ✅ main()
// Creates a linked list, manually introduces a loop,
// checks for loop, finds starting point, removes it,
// and verifies again.
// =============================================
int main() {
    // Creating linked list nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    // Linking nodes sequentially
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eighth;
    eighth -> next = ninth;
    ninth -> next = fifth; // ✅ creating a loop (90 -> 50)

    // Checking for loop
    cout << "Loop is present or not: " << checkForLoop(head) << endl;

    // Finding starting point of loop
    cout << "Starting point of LOOP is: " << startingPointLoop(head) -> data << endl;

    // Removing the loop
    removeLoop(head);

    // Printing list after loop removal
    print(head);

    // Recheck for loop after removal
    cout << "Loop is present or not: " << checkForLoop(head) << endl;

    return 0;
}
