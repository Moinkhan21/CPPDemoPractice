#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
// Each node stores:
//   • data  → integer value
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor: initialize node with data and NULL children
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
//   • Enter integer value for node
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
//   Pointer to root of constructed binary tree
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
// FUNCTION: printLeftView()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the LEFT VIEW of a binary tree.
//
// LEFT VIEW DEFINITION:
//   The set of nodes visible when the tree is viewed from the LEFT side.
//   For each level, the FIRST node encountered is part of the left view.
//
// PARAMETERS:
//   root  → current node
//   ans   → vector storing left view nodes
//   level → current depth/level in the tree
//
// CORE IDEA:
//   • Traverse tree in PREORDER manner (Root → Left → Right)
//   • When visiting a level for the FIRST time (level == ans.size()),
//     store the node’s data in ans.
//   • Left subtree is visited before right subtree to ensure
//     leftmost node is captured.
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack, where h = height of tree)
// ======================================================================
void printLeftView(Node* root, vector<int> &ans, int level) {

    // Base case: empty subtree
    if (root == NULL)
        return;

    // If this is the first node of this level,
    // then it belongs to the left view
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // First recurse on LEFT subtree
    printLeftView(root->left, ans, level + 1);

    // Then recurse on RIGHT subtree
    printLeftView(root->right, ans, level + 1);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds the binary tree, computes its left view,
// and prints the result.
// ======================================================================
int main() {

    // Build the tree
    Node* root = buildTree();

    vector<int> ans;   // Stores left view nodes
    int level = 0;     // Start from level 0 (root)

    // Compute left view
    printLeftView(root, ans, level);

    // Print result
    cout << "Printing the Left view: " << endl;
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
