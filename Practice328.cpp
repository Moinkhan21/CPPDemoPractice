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
// FUNCTION: inOrderSuccessor()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the INORDER SUCCESSOR of a given node in a BST.
//
// WHAT IS INORDER SUCCESSOR?
//   • The node with the smallest value
//     strictly greater than the given node.
//
// KEY OBSERVATION (BST PROPERTY):
//   • If current node's value > target value,
//     it can be a potential successor → move LEFT
//   • Otherwise → move RIGHT
//
// APPROACH:
//   • Start from root
//   • Traverse the tree iteratively
//   • Keep updating successor whenever a better
//     candidate is found
//
// TIME COMPLEXITY:
//   • O(h) where h = height of BST
//
// SPACE COMPLEXITY:
//   • O(1) (iterative approach)
// ======================================================================
Node* inOrderSuccessor(Node* root, Node* x) {

    // Safety check
    if (!root || !x) return NULL;

    Node* succ = NULL;   // Stores potential successor
    Node* curr = root;   // Start traversal from root

    while (curr) {

        // If current node is greater than target
        // → it can be a successor
        if (curr->data > x->data) {
            succ = curr;          // update successor
            curr = curr->left;   // try to find smaller one on left
        }
        else {
            // Move right to find larger values
            curr = curr->right;
        }
    }

    return succ;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST and finds inorder successors
// for given nodes.
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
// TEST CASES:
//   • Successor of 15 → 18
//   • Successor of 18 → 20
// ======================================================================
int main() {

    // Constructing the BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(18);

    // Test Case 1
    Node* x = root->left->right;  // Node with value 15
    Node* succ = inOrderSuccessor(root, x);

    if (succ)
        cout << "Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "No successor exists\n";

    // Test Case 2
    x = root->left->right->right; // Node with value 18
    succ = inOrderSuccessor(root, x);

    if (succ)
        cout << "Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "No successor exists\n";

    return 0;
}
