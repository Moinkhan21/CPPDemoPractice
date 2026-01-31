#include <iostream>
#include <map>
using namespace std;

// =====================================================
// STRUCT: Node
// -----------------------------------------------------
// PURPOSE:
//   Represents a node of a singly linked list.
//
// DATA MEMBERS:
//   • data → value stored in the node
//   • next → pointer to next node
// =====================================================
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// =====================================================
// FUNCTION: makeUnion
// -----------------------------------------------------
// PURPOSE:
//   Creates the UNION of two linked lists.
//
// DEFINITION (UNION):
//   • Contains all DISTINCT elements
//   • Elements are sorted in ascending order
//
// APPROACH (MAP BASED):
//   1️⃣ Traverse first linked list and store nodes in map
//   2️⃣ Traverse second linked list and store nodes in map
//   3️⃣ Map automatically removes duplicates
//   4️⃣ Map keeps keys in sorted order
//   5️⃣ Rebuild linked list from map entries
//
// WHY USE map<int, Node*>?
//   • Ensures uniqueness of elements
//   • Maintains sorted order
//
// TIME COMPLEXITY:
//   • O((N + M) log (N + M))
//
// SPACE COMPLEXITY:
//   • O(N + M)
// =====================================================
Node* makeUnion(Node* head1, Node* head2) {

    // Map to store unique values and corresponding nodes
    map<int, Node*> mp;
    Node* curr = head1;

    // -------------------------------------------------
    // Step 1: Hash first linked list
    // -------------------------------------------------
    while (curr) {
        mp[curr->data] = curr;
        curr = curr->next;
    }

    // -------------------------------------------------
    // Step 2: Hash second linked list
    // -------------------------------------------------
    curr = head2;
    while (curr) {
        mp[curr->data] = curr;
        curr = curr->next;
    }

    // -------------------------------------------------
    // Step 3: Build union linked list from map
    // -------------------------------------------------
    Node* UL = NULL;   // Head of union list
    curr = NULL;       // Pointer to build list

    for (auto it = mp.begin(); it != mp.end(); it++) {

        // First node initialization
        if (!UL) {
            UL = it->second;
            curr = UL;
        }
        // Append remaining nodes
        else {
            curr->next = it->second;
            curr = curr->next;
        }
    }

    // Terminate the list
    if (curr)
        curr->next = NULL;

    return UL;
}

// =====================================================
// FUNCTION: printList
// -----------------------------------------------------
// PURPOSE:
//   Prints the elements of a linked list.
// =====================================================
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        List 1:
        10 -> 15 -> 5 -> 20

        List 2:
        8 -> 4 -> 2 -> 10

        Union (Sorted & Unique):
        2 4 5 8 10 15 20
    */

    // First linked list
    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(20);

    // Second linked list
    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    // Create union list
    Node* unionList = makeUnion(head1, head2);

    cout << "Union of the two linked lists:\n";
    printList(unionList);

    return 0;
}
