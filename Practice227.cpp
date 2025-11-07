#include <iostream>
#include <unordered_map>
using namespace std;

// =====================================================
// ✅ Node structure for linked list with random pointer
// Each node contains:
// - val: data value
// - next: pointer to the next node
// - random: pointer to any random node in the list (or NULL)
// =====================================================
class Node {
public:
    int val;
    Node* next;
    Node* random;

    // Constructor to initialize the node
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// =====================================================
// ✅ Helper Function: helper()
// Purpose: Recursively clones the linked list using a map
// Parameters:
// - head: pointer to the current node in the original list
// - mp: unordered_map that stores mapping between original node → cloned node
//
// Working:
// - Creates a clone node for each original node
// - Stores mapping (so we can later link random pointers correctly)
// - Recursively clones the remaining list
// =====================================================
Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
    // Base case: if original list ends, return NULL
    if(head == NULL) return NULL;

    // ---------------------------------------------
    // Step 1: Create a new cloned node with same value as current node
    // ---------------------------------------------
    Node* newHead = new Node(head->val);

    // ---------------------------------------------
    // Step 2: Store mapping between original node → cloned node
    // This helps in correctly assigning random pointers later
    // ---------------------------------------------
    mp[head] = newHead;

    // ---------------------------------------------
    // Step 3: Recursively copy the rest of the list
    // newHead->next will point to the cloned version of head->next
    // ---------------------------------------------
    newHead->next = helper(head->next, mp);

    // ---------------------------------------------
    // Step 4: Set the random pointer for cloned node
    // If original node had a random pointer, use map to get
    // the cloned version of that random node
    // ---------------------------------------------
    if(head->random)
        newHead->random = mp[head->random];

    // ---------------------------------------------
    // Step 5: Return the cloned node (head of cloned sublist)
    // ---------------------------------------------
    return newHead;
}

// =====================================================
// ✅ Function: copyRandomList()
// Purpose: Creates a deep copy of a linked list with random pointers
// Approach:
// - Uses a hash map to map original nodes to their corresponding cloned nodes
// - Ensures that both `next` and `random` pointers are correctly copied
// =====================================================
Node* copyRandomList(Node* head) {
    // map to store mapping: original node -> cloned node
    unordered_map<Node*, Node*> mp;  // original -> cloned node map
    
    // Call helper() to perform deep copy using recursion
    return helper(head, mp);
}

// =====================================================
// ✅ Utility Function: printList()
// Prints both the `val` and `random` pointer values for verification
// =====================================================
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

// =====================================================
// ✅ MAIN FUNCTION — Driver Code
// Demonstrates cloning of a linked list with random pointers
// =====================================================
int main() {
    // ---------------------------------------------
    // Step 1: Create list → 1 -> 2 -> 3
    // ---------------------------------------------
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // ---------------------------------------------
    // Step 2: Assign random pointers
    // 1 → random → 2
    // 2 → random → 3
    // 3 → random → 1
    // ---------------------------------------------
    head->random = head->next;               // 1 -> 2
    head->next->random = head->next->next;   // 2 -> 3
    head->next->next->random = head;         // 3 -> 1

    // ---------------------------------------------
    // Step 3: Print original list before cloning
    // ---------------------------------------------
    cout << "Original List:\n";
    printList(head);

    // ---------------------------------------------
    // Step 4: Create cloned list using deep copy function
    // ---------------------------------------------
    Node* clone = copyRandomList(head);

    // ---------------------------------------------
    // Step 5: Print cloned list to verify deep copy
    // ---------------------------------------------
    cout << "\nCloned List:\n";
    printList(clone);

    return 0;
}
