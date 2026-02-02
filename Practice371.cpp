#include <iostream>
#include <unordered_map>
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
// FUNCTION: findIntersection
// -----------------------------------------------------
// PURPOSE:
//   Finds the INTERSECTION of two linked lists.
//
// DEFINITION (INTERSECTION):
//   • Contains elements common to both lists
//   • Frequency of elements is respected
//   • Order follows the first linked list
//
// APPROACH (HASHING):
//   1️⃣ Store frequency of elements of second list
//   2️⃣ Traverse first list
//   3️⃣ If element exists in map with freq > 0,
//       add it to intersection list
//   4️⃣ Decrease frequency to avoid duplicates
//
// WHY unordered_map?
//   • O(1) average lookup
//   • Efficient for frequency counting
//
// TIME COMPLEXITY:
//   • O(N + M)
//
// SPACE COMPLEXITY:
//   • O(M)
// =====================================================
Node* findIntersection(Node* head1, Node* head2) {

    unordered_map<int, int> map;
    Node* curr = head2;

    // -------------------------------------------------
    // Step 1: Hash elements of second linked list
    // -------------------------------------------------
    while (curr) {
        map[curr->data]++;
        curr = curr->next;
    }

    Node* IL = NULL;   // Head of intersection list
    Node* it = NULL;   // Tail pointer for intersection list
    curr = head1;

    // -------------------------------------------------
    // Step 2: Traverse first linked list
    // -------------------------------------------------
    while (curr) {

        // Check if current element exists in list 2
        if (map.find(curr->data) != map.end() &&
            map[curr->data] > 0) {

            // First node of intersection list
            if (!IL) {
                IL = curr;
                it = IL;
            }
            // Append further nodes
            else {
                it->next = curr;
                it = it->next;
            }

            // Decrease frequency to handle duplicates
            map[curr->data]--;   // Important fix
        }

        curr = curr->next;
    }

    // -------------------------------------------------
    // Step 3: Properly terminate intersection list
    // -------------------------------------------------
    if (it)
        it->next = NULL;

    return IL;
}

// =====================================================
// FUNCTION: printList
// -----------------------------------------------------
// PURPOSE:
//   Prints all elements of a linked list.
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
        8 -> 4 -> 2 -> 10 -> 5

        Intersection:
        10 -> 5
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
    head2->next->next->next->next = new Node(5);

    // Find intersection
    Node* intersection = findIntersection(head1, head2);

    cout << "Intersection of the two linked lists:\n";
    printList(intersection);

    return 0;
}
