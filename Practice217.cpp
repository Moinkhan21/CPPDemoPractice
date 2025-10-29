#include <iostream>
using namespace std;

// ===============================
// ✅ Node class definition
// Represents a single node in the linked list
// ===============================
class Node {
public:
    int data;       // Stores the node's data
    Node* next;     // Pointer to the next node in the list

    // ✅ Constructor initializes the node's data and sets next to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ===============================
// ✅ Function: checkPalindrome
// Checks if a given singly linked list is a palindrome using iteration.
// ===============================
bool checkPalindrome(Node*& head) {

    // ✅ Step 1: Handle edge cases
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return true; // Empty list is considered palindrome
    }

    if (head->next == NULL) {
        // ✅ Only one node → Always a palindrome
        return true;
    }

    // ✅ Step 2: Find the middle node using slow and fast pointer approach
    // - 'slow' moves one step at a time
    // - 'fast' moves two steps at a time
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // After loop → 'slow' is pointing at the middle node

    // ✅ Step 3: Reverse the second half of the linked list (in-place)
    Node* prev = NULL;
    Node* curr = slow->next;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse the link
        prev = curr;         // Move prev one step ahead
        curr = next;         // Move curr one step ahead
    }

    // ✅ 'prev' now points to the head of the reversed second half
    slow->next = prev; // Join the two halves

    // ✅ Step 4: Compare first half and reversed second half
    Node* temp1 = head;      // Start from beginning
    Node* temp2 = prev;      // Start from reversed second half

    while (temp2 != NULL) {
        if (temp1->data != temp2->data) {
            // ❌ Mismatch found → Not a palindrome
            return false;
        } else {
            // ✅ Move both pointers one step ahead
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // ✅ Step 5: If all elements matched → It's a palindrome
    return true;
}

// ===============================
// ✅ Main function
// Creates a sample linked list and checks palindrome property
// ===============================
int main() {

    // ✅ Creating linked list nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);

    // ✅ Linking all nodes together
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    // ✅ Check if the linked list is a palindrome
    bool isPalindrome = checkPalindrome(head);

    // ✅ Display the result
    if (isPalindrome) {
        cout << "LL is a valid palindrome" << endl;
    } else {
        cout << "LL is not a valid palindrome" << endl;
    }

    return 0;
}
