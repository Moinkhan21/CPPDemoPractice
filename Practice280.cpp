#include <iostream>
using namespace std;

class Node {
public:
    int data;      // stores value of the node
    Node* left;    // pointer to left child
    Node* right;   // pointer to right child

    // ------------------------------------------------------------------
    // CONSTRUCTOR:
    // Initializes a new node with given data.
    // Left and right children are set to NULL (no children initially).
    // ------------------------------------------------------------------
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
//   Builds a binary tree using recursive input from the user.
//   Input is taken in PREORDER fashion:
//      1. Read current node data
//      2. Recursively build left subtree
//      3. Recursively build right subtree
//
// INPUT RULE:
//   Enter `-1` when you want to indicate "no node" (NULL pointer).
//
// EXAMPLE INPUT SEQUENCE:
//   1 2 -1 -1 3 -1 -1
//   Meaning:
//     1
//    / \
//   2   3
//
// HOW IT WORKS RECURSIVELY:
//   • User enters data for the current node
//   • If data is -1 → return NULL
//   • Otherwise create a new node
//   • Recursively ask for left subtree
//   • Recursively ask for right subtree
//
// RETURNS:
//   Pointer to the root node of the constructed tree.
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // -----------------------------
    // BASE CASE:
    // If user enters -1 → no node
    // -----------------------------
    if (data == -1) {
        return NULL;
    }

    // --------------------------------------------------------
    // STEP A: Create a new node with current data
    // STEP B: Recursively build left subtree
    // STEP C: Recursively build right subtree
    // --------------------------------------------------------
    Node* root = new Node(data);

    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();   // recursive call for left child

    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();  // recursive call for right child

    return root; // return constructed node
}

int main() {
    Node* root = NULL;

    // Build tree from user input using preorder recursive structure
    root = buildTree();

    return 0;
}
