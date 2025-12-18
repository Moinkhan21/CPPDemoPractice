#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
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

    // Constructor initializes node with given data
    // and sets both children to NULL
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree recursively using PREORDER input.
//
// INPUT RULE:
//   • Enter an integer value for a node
//   • Enter -1 to represent NULL (no node)
//
// PROCESS (PREORDER: Node → Left → Right):
//   1. Read data
//   2. If data == -1 → return NULL
//   3. Create current node
//   4. Recursively build left subtree
//   5. Recursively build right subtree
//
// RETURNS:
//   Pointer to the root of the constructed binary tree
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    // Base case: no node
    if (data == -1)
        return NULL;

    // Create current node
    Node* root = new Node(data);

    // Build left subtree
    cout << "Enter LEFT child of " << data << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter RIGHT child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: printRightView()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the RIGHT VIEW of a binary tree.
//
// RIGHT VIEW DEFINITION:
//   The set of nodes visible when the tree is viewed from the RIGHT side.
//   For each level, the FIRST node encountered is part of the right view.
//
// PARAMETERS:
//   root  → current node
//   ans   → vector storing right view nodes
//   level → current depth/level of the tree
//
// CORE IDEA:
//   • Traverse the tree in PREORDER manner but with order:
//         Root → Right → Left
//   • When visiting a level for the FIRST time
//     (i.e., level == ans.size()),
//     store that node’s value in ans.
//   • Visiting RIGHT child before LEFT ensures the
//     rightmost node of each level is captured.
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack, h = height of tree)
// ======================================================================
void printRightView(Node* root, vector<int> &ans, int level) {

    // Base case: empty subtree
    if (root == NULL)
        return;

    // If this level is visited for the first time,
    // current node belongs to the right view
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // First traverse RIGHT subtree
    printRightView(root->right, ans, level + 1);

    // Then traverse LEFT subtree
    printRightView(root->left, ans, level + 1);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds the binary tree, computes its right view,
// and prints the result.
// ======================================================================
int main() {

    // Build the binary tree
    Node* root = buildTree();

    vector<int> ans;   // Stores right view nodes
    int level = 0;     // Root level starts from 0

    // Compute right view
    printRightView(root, ans, level);

    // Print the right view
    cout << "Printing the right view: " << endl;
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
