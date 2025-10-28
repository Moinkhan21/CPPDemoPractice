#include <iostream>
using namespace std;

// ===============================
// ✅ Node class definition
// Each node stores an integer data and a pointer to the next node.
// ===============================
class Node {
    public:
    int data;       // Stores data value of node
    Node* next;     // Pointer to the next node

    // ✅ Constructor to initialize the node with data
    Node(int data) {
        this -> data = data;   // Assign the data value
        this -> next = NULL;   // Initialize next pointer as NULL
    }
};

// ===============================
// ✅ Function to print the linked list
// Traverses from head to end and prints each node’s data
// ===============================
void print(Node* head) {
    Node* temp = head;  // Temporary pointer to iterate
    while(temp != NULL) {
        cout << temp -> data << "->";   // Print current node’s data
        temp = temp -> next;            // Move to next node
    }
    cout << endl;
}

// ===============================
// ✅ Function to find the middle node of a linked list using two-pointer approach
// Slow moves 1 step at a time, Fast moves 2 steps at a time
// When Fast reaches the end, Slow will be at the middle
// ===============================
Node* getMiddle(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty" << endl;   // Empty list case
        return head;
    }

    if(head -> next == NULL) {
        //Only 1 node in LL
        return head;  // If only one node exists, it’s the middle
    }

    //LL have more than one node
    Node* slow = head;           // Moves 1 step each iteration
    Node* fast = head -> next;   // Moves 2 steps each iteration

    // Loop continues while fast and slow are valid
    while(slow != NULL && fast != NULL) {
        fast = fast -> next;          // Move fast by 1
        if(fast != NULL) {
            fast = fast -> next;      // Move fast by another 1 (total 2 steps)
            slow = slow -> next;      // Move slow by 1
        }
    }
    return slow;  // When loop ends, slow is at the middle
}

// ===============================
// ✅ Function to find length of the linked list
// Simply counts nodes until NULL is reached
// ===============================
int getLength(Node* head) {
    int len = 0;           // Initialize length counter
    Node* temp = head;     // Temporary pointer to traverse list
    while (temp != NULL)
    {
        temp = temp -> next;  // Move to next node
        len++;                // Increment counter
    }
    return len;  // Return total count
}

// ===============================
// ✅ Function to reverse K nodes in a linked list
// This version uses recursion for next segments
// ===============================
Node* reverseKNodes(Node* &head, int k) {

    if(head == NULL) {
        cout << "LL is empty" << endl;  // If list is empty
        return NULL;
    }

    int len = getLength(head);  // Find total length of linked list
    if(k > len) {
        cout << "Enter valid value for K " << endl;  // Invalid case
        return head;
    }

    //It means number of nodes in LL is >== k
    //Step A: reverse first k nodes of LL
    Node* prev = NULL;           // Points to previous node (initially NULL)
    Node* curr = head;           // Current node to process
    Node* forward = curr -> next; // Stores next node (to avoid losing reference)
    int count = 0;               // Counter for k nodes

    // ✅ Reverse first k nodes
    while (count < k)
    {
        forward = curr -> next;   // Save next node before breaking the link
        curr -> next = prev;      // Reverse the current node’s pointer
        prev = curr;              // Move prev one step ahead
        curr = forward;           // Move curr one step ahead
        count++;                  // Increment counter
    }
    
    //Step B: revursive call
    if(forward != NULL) {
        //We still have nodes left to reverse
        head -> next = reverseKNodes(forward, k);  // Recursive call for remaining nodes
    }

    //Step C: return head of the modified LL
    return prev;  // Return new head after reversal of current group
}

// ===============================
// ✅ Main function: program entry point
// Creates a linked list, prints it, reverses it in groups of K, and prints again
// ===============================
int main() {
    // ✅ Creating nodes manually and linking them together
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;

    // ✅ Print original linked list
    print(head);
    cout << endl;

    // ✅ Reverse K nodes (here, K = 3)
    head = reverseKNodes(head, 3);

    // ✅ Print the modified linked list after reversal
    print(head);
    
    return 0;
}
