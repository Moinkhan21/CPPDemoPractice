#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a singly linked list.
//
// Each node contains:
//   • data → value (0 / 1 / 2)
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
//   Prints the linked list.
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
// FUNCTION: sortZeroOneTwo()
// ----------------------------------------------------------------------
// PURPOSE:
//   Sorts a linked list containing only 0s, 1s, and 2s
//   using COUNTING METHOD.
//
// APPROACH:
//
//   STEP 1:
//     Count number of 0s, 1s, and 2s
//
//   STEP 2:
//     Overwrite linked list with:
//       • all 0s
//       • then 1s
//       • then 2s
//
// IMPORTANT:
//   This approach modifies DATA, not structure.
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
// ======================================================================
void sortZeroOneTwo(Node*& head) {

    // --------------------------------------------------
    // Step 1: Count occurrences
    // --------------------------------------------------
    int zero = 0, one = 0, two = 0;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else
            two++;

        temp = temp->next;
    }

    // --------------------------------------------------
    // Step 2: Overwrite values
    // --------------------------------------------------
    temp = head;

    // Fill 0s
    while (zero--) {
        temp->data = 0;
        temp = temp->next;
    }

    // Fill 1s
    while (one--) {
        temp->data = 1;
        temp = temp->next;
    }

    // Fill 2s
    while (two--) {
        temp->data = 2;
        temp = temp->next;
    }
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    // Input: 1 → 2 → 2 → 0 → 0 → 0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(0);

    cout << "Input LL: ";
    print(head);

    sortZeroOneTwo(head);

    cout << "Sorted LL: ";
    print(head);

    return 0;
}