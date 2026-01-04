#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • data  → value of the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node value
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree recursively using user input.
//
// INPUT RULE:
//   • Enter -1 to indicate NULL node
//
// APPROACH:
//   • Read current node value
//   • Recursively build left subtree
//   • Recursively build right subtree
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
Node* buildTree() {

    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    // Base case: NULL node
    if (data == -1)
        return NULL;

    // Create current node
    Node* root = new Node(data);

    // Build left subtree
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: kthAncestor()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds and prints the Kth ancestor of a given node value `p`.
//
// PARAMETERS:
//   • root → current node
//   • k    → reference variable tracking ancestor distance
//   • p    → target node value
//
// RETURN VALUE:
//   • true  → if target node exists in subtree
//   • false → otherwise
//
// CORE IDEA:
//   • Traverse tree to find target node `p`
//   • While returning back (backtracking):
//       - Decrease k
//       - When k becomes 0 → current node is the answer
//
// IMPORTANT:
//   • k is passed by reference to maintain state
//   • Once answer is found, k is set to -1 to stop further printing
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
bool kthAncestor(Node* root, int &k, int p) {

    // Base case: empty tree
    if (root == NULL)
        return false;

    // If current node is the target node
    if (root->data == p) {
        return true;
    }

    // Search in left and right subtrees
    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // While returning back from recursion
    // Check if target was found in any subtree
    if (leftAns || rightAns)
        k--;

    // When k becomes 0, current node is the Kth ancestor
    if (k == 0) {
        cout << "Answer: " << root->data << endl;
        k = -1;   // Prevent further ancestor printing
    }

    return leftAns || rightAns;
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    Node* root = NULL;

    // Build binary tree
    root = buildTree();

    int k = 1;   // Kth ancestor to find
    int p = 4;   // Target node value

    bool found = kthAncestor(root, k, p);

    return 0;
}
