#include <iostream>
#include <map>
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
// Make Union of Two Linked Lists
// ===============================
Node* makeUnion(Node* head1, Node* head2) {

    map<int, Node*> mp;
    Node* curr = head1;

    // Hash first list
    while (curr) {
        mp[curr->data] = curr;
        curr = curr->next;
    }

    // Hash second list
    curr = head2;
    while (curr) {
        mp[curr->data] = curr;
        curr = curr->next;
    }

    Node* UL = NULL;
    curr = NULL;

    // Build union list from map
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (!UL) {
            UL = it->second;
            curr = UL;
        }
        else {
            curr->next = it->second;
            curr = curr->next;
        }
    }

    if (curr)
        curr->next = NULL;

    return UL;
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
        List 2: 8 -> 4 -> 2 -> 10

        Union: 2 4 5 8 10 15 20
    */

    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(20);

    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    Node* unionList = makeUnion(head1, head2);

    cout << "Union of the two linked lists:\n";
    printList(unionList);

    return 0;
}
