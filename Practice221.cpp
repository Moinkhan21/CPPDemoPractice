#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a singly linked list.
//
// Each node contains:
//   • data → integer value
//   • next → pointer to next node
// ======================================================================
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ======================================================================
// FUNCTION: print()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the linked list elements.
//
// TIME COMPLEXITY: O(N)
// ======================================================================
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// ======================================================================
// FUNCTION: reverse()
// ----------------------------------------------------------------------
// PURPOSE:
//   Reverses a singly linked list.
//
// APPROACH:
//   Iterative (3-pointer method)
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
// ======================================================================
Node* reverse(Node* head) {

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {

        Node* next = curr->next; // store next node
        curr->next = prev;       // reverse link
        prev = curr;             // move prev forward
        curr = next;             // move curr forward
    }

    return prev;
}

// ======================================================================
// FUNCTION: solve()
// ----------------------------------------------------------------------
// PURPOSE:
//   Adds two numbers represented as linked lists.
//
// REPRESENTATION:
//
//   Example:
//     List1: 2 → 4  (represents 24)
//     List2: 2 → 3 → 4 (represents 234)
//
// OUTPUT:
//     2 → 5 → 8 (represents 258)
//
// APPROACH:
//
//   1️⃣ Reverse both linked lists
//       → makes addition easier (units place first)
//
//   2️⃣ Add corresponding nodes with carry
//
//   3️⃣ Handle remaining nodes and carry
//
//   4️⃣ Reverse the result to restore correct order
//
// TIME COMPLEXITY: O(N + M)
// SPACE COMPLEXITY: O(max(N, M))
// ======================================================================
Node* solve(Node*& head1, Node*& head2) {

    // --------------------------------------------------
    // Step 1: Reverse both lists
    // --------------------------------------------------
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;

    // --------------------------------------------------
    // Step 2: Add nodes while both lists exist
    // --------------------------------------------------
    while (head1 != NULL && head2 != NULL) {

        int sum = carry + head1->data + head2->data;

        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        // Insert into answer list
        if (ansHead == NULL) {
            ansHead = newNode;
            ansTail = newNode;
        }
        else {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    // --------------------------------------------------
    // Step 3: Process remaining nodes of head1
    // --------------------------------------------------
    while (head1 != NULL) {

        int sum = carry + head1->data;

        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;

        head1 = head1->next;
    }

    // --------------------------------------------------
    // Step 4: Process remaining nodes of head2
    // --------------------------------------------------
    while (head2 != NULL) {

        int sum = carry + head2->data;

        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;

        head2 = head2->next;
    }

    // --------------------------------------------------
    // Step 5: Handle remaining carry
    // --------------------------------------------------
    while (carry != 0) {

        int digit = carry % 10;
        carry = carry / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // --------------------------------------------------
    // Step 6: Reverse result list
    // --------------------------------------------------
    ansHead = reverse(ansHead);

    return ansHead;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    // List 1: 2 → 4 (represents 24)
    Node* head1 = new Node(2);
    head1->next = new Node(4);

    // List 2: 2 → 3 → 4 (represents 234)
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    // Perform addition
    Node* ans = solve(head1, head2);

    // Print result
    print(ans);

    return 0;
}