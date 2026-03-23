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
// FUNCTION: sortLL()
// ----------------------------------------------------------------------
// PURPOSE:
//   Sorts a linked list containing only 0s, 1s, and 2s.
//
// APPROACH: Three Dummy Lists (Dutch National Flag Concept)
//
// CORE IDEA:
//
//   1️⃣ Create 3 separate lists:
//        • zero list → nodes with data = 0
//        • one list  → nodes with data = 1
//        • two list  → nodes with data = 2
//
//   2️⃣ Traverse original list and distribute nodes
//
//   3️⃣ Merge the three lists
//
// ADVANTAGE:
//   • No extra node creation (reusing existing nodes)
//   • Stable and efficient
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
// ======================================================================
Node* sortLL(Node* head) {

    // --------------------------------------------------
    // Edge Cases
    // --------------------------------------------------
    if (head == NULL) {
        cout << "LL is empty\n";
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    // --------------------------------------------------
    // Step 1: Create dummy nodes for 3 lists
    // --------------------------------------------------
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // --------------------------------------------------
    // Step 2: Traverse original list
    // --------------------------------------------------
    Node* curr = head;

    while (curr != NULL) {

        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL; // detach node

        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        }
        else {
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // --------------------------------------------------
    // Step 3: Remove dummy nodes (1s and 2s)
    // --------------------------------------------------
    Node* temp = oneHead;
    oneHead = oneHead->next;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    delete temp;

    // --------------------------------------------------
    // Step 4: Merge lists
    // --------------------------------------------------

    // Attach 0 → 1
    if (oneHead != NULL) {
        zeroTail->next = oneHead;

        // Attach 1 → 2
        if (twoHead != NULL) {
            oneTail->next = twoHead;
        }
    }
    else {
        // If no 1s, attach 0 → 2 directly
        if (twoHead != NULL) {
            zeroTail->next = twoHead;
        }
    }

    // --------------------------------------------------
    // Step 5: Remove zero dummy node
    // --------------------------------------------------
    temp = zeroHead;
    zeroHead = zeroHead->next;
    delete temp;

    return zeroHead;
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

    head = sortLL(head);

    cout << "Sorted LL: ";
    print(head);

    return 0;
}