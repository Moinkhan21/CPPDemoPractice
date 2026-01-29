#include <iostream>
#include <unordered_map>
using namespace std;

// ===============================
// Node Definition
// ===============================
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// ===============================
// Find Intersection of Two Lists
// ===============================
Node* findIntersection(Node* head1, Node* head2) {

    unordered_map<int, int> map;
    Node* curr = head2;

    // Hash elements of list 2
    while (curr) {
        map[curr->data]++;
        curr = curr->next;
    }

    Node* IL = NULL;
    Node* it = NULL;
    curr = head1;

    // Traverse list 1
    while (curr) {
        if (map.find(curr->data) != map.end() && map[curr->data] > 0) {

            if (!IL) {
                IL = curr;
                it = IL;
            }
            else {
                it->next = curr;
                it = it->next;
            }

            map[curr->data]--;   // ✅ FIXED
        }
        curr = curr->next;
    }

    if (it)
        it->next = NULL;   // safety check

    return IL;
}

// ===============================
// Print Linked List
// ===============================
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        List 1: 10 -> 15 -> 5 -> 20
        List 2: 8 -> 4 -> 2 -> 10 -> 5

        Intersection: 10 -> 5
    */

    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(20);

    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);
    head2->next->next->next->next = new Node(5);

    Node* intersection = findIntersection(head1, head2);

    cout << "Intersection of the two linked lists:\n";
    printList(intersection);

    return 0;
}
