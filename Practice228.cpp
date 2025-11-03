#include <iostream>
using namespace std;

// ================================
// ✅ Node structure (represents each node in LL)
// Each node contains:
//   ➤ val     : integer data
//   ➤ next    : pointer to next node
//   ➤ random  : pointer to ANY node in the list or NULL
// ================================
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ==========================================================
// ✅ Function to clone a Linked List with random pointers
// Approach: Iterative (O(n) time, O(1) extra space)
// Steps:
//   1️⃣ Insert cloned nodes in between original nodes
//   2️⃣ Set random pointers for cloned nodes
//   3️⃣ Separate original & cloned list
// ==========================================================
Node* copyRandomList(Node* head) {
    // If head is NULL, return NULL (empty list case)
    if(!head) return NULL;

    // -------------------------------
    // Step 1: Create clones & insert right after each original node
    // Example:
    // Original: 1 -> 2 -> 3
    // After Step 1: 1 -> 1' -> 2 -> 2' -> 3 -> 3'
    // -------------------------------
    Node* it = head;
    while(it) {
        Node* clonedNode = new Node(it->val);  // Create clone
        clonedNode->next = it->next;           // Clone points to original's next
        it->next = clonedNode;                 // Insert clone after original
        it = clonedNode->next;                 // Move to next original node
    }

    // -------------------------------
    // Step 2: Assign random pointers to cloned nodes
    // Logic: clone->random = original->random->next (because right next is clone)
    // -------------------------------
    it = head;
    while(it) {
        if(it->random)
            it->next->random = it->random->next; // Set clone random pointer
        it = it->next->next;  // Move to next original node
    }

    // -------------------------------
    // Step 3: Separate original & cloned list
    // Restore original list and extract cloned list
    // -------------------------------
    it = head;               
    Node* clonedHead = head->next; // Head of cloned list

    while(it) {
        Node* clonedNode = it->next;       // Clone node
        it->next = clonedNode->next;       // Original next back to original
        if(clonedNode->next)
            clonedNode->next = clonedNode->next->next; // Clone next to next clone
        it = it->next; // Move to next original node
    }
    
    return clonedHead; // Return start of cloned list
}

// ==========================================
// ✅ Utility: Print linked list with random pointers
// Format: Node value and its Random node value
// ==========================================
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << "Node: " << temp->val;
        if(temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Create LL: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assign random pointers
    head->random = head->next;               // 1 -> 2
    head->next->random = head->next->next;   // 2 -> 3
    head->next->next->random = head;         // 3 -> 1

    cout << "Original List:\n";
    printList(head);

    Node* cloned = copyRandomList(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}
