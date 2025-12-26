#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    // and sets both children to NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: findPredecessor()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the INORDER PREDECESSOR of a given node `p`
//   in a Binary Search Tree.
//
// WHAT IS INORDER PREDECESSOR?
//   • The node with the largest value smaller than `p`
//   • Appears just BEFORE `p` in inorder traversal
//
// APPROACH (Iterative using BST property):
//   • Start from root
//   • If current node < p:
//       - Current node is a potential predecessor
//       - Move to right subtree (try to find closer value)
//   • Else:
//       - Move to left subtree
//
// WHY THIS WORKS?
//   • BST ordering allows pruning half of the tree
//
// TIME COMPLEXITY:
//   Average: O(log n)
//   Worst:   O(n) (skewed tree)
//
// SPACE COMPLEXITY: O(1)
// ======================================================================
Node* findPredecessor(Node* root, Node* p) {

    // Safety check: invalid input
    if (!root || !p) return NULL;

    Node* pred = NULL;   // Stores latest valid predecessor
    Node* curr = root;  // Start traversal from root

    while (curr) {

        // If current node value is smaller than p,
        // it can be a predecessor
        if (curr->data < p->data) {
            pred = curr;            // Update predecessor
            curr = curr->right;     // Move right for closer value
        }
        else {
            // Current value >= p, so move left
            curr = curr->left;
        }
    }

    return pred;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST and finds inorder predecessors
// for different target nodes.
//
// TREE STRUCTURE:
//
//            20
//           /  \
//         10    30
//        /  \
//       5   15
//            \
//             18
//
// INORDER TRAVERSAL:
//   5 10 15 18 20 30
//
// EXAMPLES:
//   • Predecessor of 20 → 18
//   • Predecessor of 15 → 10
// ======================================================================
int main() {

    // Constructing the BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(18);

    // -------------------------------
    // Test Case 1
    // -------------------------------
    Node* p = root;  // Node with value 20
    Node* pred = findPredecessor(root, p);

    if (pred)
        cout << "Predecessor of " << p->data << " is " << pred->data << endl;
    else
        cout << "No predecessor exists\n";

    // -------------------------------
    // Test Case 2
    // -------------------------------
    p = root->left->right; // Node with value 15
    pred = findPredecessor(root, p);

    if (pred)
        cout << "Predecessor of " << p->data << " is " << pred->data << endl;
    else
        cout << "No predecessor exists\n";

    return 0;
}
