#include <iostream>
using namespace std;

// ===============================
// ✅ Node Structure for Linked List
// ===============================
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ===============================
// ✅ Function: linkdelete
// Keeps M nodes, deletes next N nodes, and repeats
// ===============================
void linkdelete(Node * head, int M, int N) {
    if(!head) return; // Base case, stop when list ends

    Node* it = head;  // Pointer to traverse

    // ✅ Move pointer to the Mth node (keep these nodes)
    for(int i = 0; i < M - 1 && it; ++i) {
        it = it -> next;
    }

    // If we reach end before finishing M nodes → return
    if(!it) return;

    // ✅ Mth node pointer
    Node* MthNode = it;

    // ✅ Start deleting next N nodes
    it = MthNode -> next;
    for(int i = 0; i < N && it; ++i) {
        Node* temp = it -> next; // Save next node
        delete it;               // Delete current node
        it = temp;               // Move forward
    }

    // ✅ Connect Mth node to the node after deleted nodes
    MthNode -> next = it;

    // ✅ Recursive call to process remaining list
    linkdelete(it, M, N);
}

// ===============================
// ✅ Function to Print Linked List
// ===============================
void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head -> next;
    }
    cout << endl;
}

// ===============================
// ✅ Main Function: Test linkdelete()
// Example: M = 2, N = 2
// Input Linked List: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
// Output: 1 → 2 → 5 → 6
// Explanation:
// Keep 1,2 → delete 3,4 → keep 5,6 → delete 7,8
// ===============================
int main() {

    // 🔹 Creating Linked List nodes manually
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    cout << "Original List: ";
    printList(head);

    int M = 2, N = 2; // Keep 2 nodes, delete 2 nodes

    linkdelete(head, M, N);

    cout << "Modified List after deleting " << N 
         << " nodes after every " << M << " nodes: ";
    printList(head);

    return 0;
}
