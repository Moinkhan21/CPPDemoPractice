#include <iostream>
using namespace std;

// ==============================================
// ✅ Node class definition for Linked List
// Each node contains integer data and a pointer
// to the next node in the list.
// ==============================================
class Node {
    public:
        int data;     // stores the value of the node
        Node* next;   // pointer to the next node

    // Constructor to initialize data and next pointer
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// ==============================================
// ✅ Function: reverse()
// This function reverses a linked list iteratively.
// It uses three pointers: prev, curr, and next.
// The head of the reversed list is returned.
// ==============================================
Node* reverse(Node* head) {

    Node* prev = NULL;         // Initially, no previous node exists
    Node* curr = head;         // Start reversing from the head node
    Node* next = curr -> next; // Temporarily store the next node to avoid losing link

    // Loop runs until all nodes are reversed
    while(curr != NULL) {
        next = curr -> next;   // Save the next node
        curr -> next = prev;   // Reverse the current node’s pointer
        prev = curr;           // Move 'prev' one step ahead
        curr = next;           // Move 'curr' one step ahead
    }

    // At the end, 'prev' will be the new head of the reversed list
    return prev;
}

// ==============================================
// ✅ Function: checkPalindrome()
// Checks whether the given linked list is a palindrome.
// Steps:
//   A. Find the middle node using the slow-fast pointer method.
//   B. Reverse the second half of the list.
//   C. Compare the first and second halves node by node.
// ==============================================
bool checkPalindrome(Node*& head) {

    if(head == NULL) {
        cout << "LL is empty" << endl;
        return true;   // Empty list is considered a palindrome
    }

    if(head -> next == NULL) {
        //Only 1 node
        return true;   // Single-node list is always a palindrome
    }

    // >1 node in LL

    // Step A: find the middle node using the slow-fast pointer approach
    Node* slow = head;
    Node* fast = head -> next;

    // 'fast' moves two steps, 'slow' moves one step
    // When 'fast' reaches end, 'slow' will be at the middle
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    // Slow pointer is pointing to the middle node

    // Step B: reverse LL after middle/slow node
    Node* reverseLLKaHead = reverse(slow -> next);

    // Join the reversed LL into the left part
    slow -> next = reverseLLKaHead;

    // Step C: start comparison;
    Node* temp1 = head;             // Pointer for first half
    Node* temp2 = reverseLLKaHead;  // Pointer for second (reversed) half

    // Compare both halves node by node
    while(temp2 != NULL) {
        if(temp1 -> data != temp2 -> data) {
            // Not a palindrome — mismatch found
            return false;
        }
        else {
            //If data is equal, then aage badh jao (move ahead)
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    // If all data matched, it's a palindrome
    return true;
}

// ==============================================
// ✅ main()
// Creates a linked list and checks if it’s a palindrome.
// ==============================================
int main() {

    // Creating nodes with given values
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);

    // Linking nodes sequentially
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = NULL;

    // Function call to check palindrome property
    bool isPalindrome = checkPalindrome(head);

    // Display result
    if(isPalindrome) {
        cout << "LL is a valid palindrome" << endl;
    }
    else {
        cout << "LL is not a valid palindrome" << endl;
    }

    return 0;
}
