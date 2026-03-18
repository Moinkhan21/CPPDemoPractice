#include <iostream>
#include <vector>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// The constructor initializes the node value
// and sets both children to NULL.
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

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
//   Builds a binary tree using PREORDER input.
//
// INPUT RULE:
//   • Enter value for node
//   • Enter -1 → represents NULL node
//
// PROCESS (Preorder):
//   Node → Left → Right
//
// RETURNS:
//   Pointer to root of constructed tree
//
// TIME COMPLEXITY: O(N)
// ======================================================================
Node* buildTree() {

    int data;
    cout << "Enter data: ";
    cin >> data;

    // Base case: NULL node
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
// WHAT IS RIGHT VIEW?
//
//   The set of nodes visible when the tree is viewed
//   from the RIGHT side.
//
// RULE:
//   For each level → only ONE node is visible
//   (the rightmost node)
//
// APPROACH:
//
//   Modified Preorder Traversal:
//
//       Root → Right → Left
//
// CORE IDEA:
//
//   • Maintain current level
//   • If level == ans.size()
//       → first node of this level → store it
//
// WHY RIGHT FIRST?
//
//   Ensures the rightmost node is visited first,
//   so it gets stored before left nodes.
//
// PARAMETERS:
//
//   root  → current node
//   ans   → stores right view nodes
//   level → current depth of tree
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H)
// ======================================================================
void printRightView(Node* root, vector<int> &ans, int level) {

    // Base case
    if (root == NULL)
        return;

    // --------------------------------------------------
    // If visiting this level for the first time
    // --------------------------------------------------
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // --------------------------------------------------
    // Traverse RIGHT subtree first
    // --------------------------------------------------
    printRightView(root->right, ans, level + 1);

    // --------------------------------------------------
    // Traverse LEFT subtree
    // --------------------------------------------------
    printRightView(root->left, ans, level + 1);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a binary tree and prints its right view.
//
// SAMPLE TREE:
//
//            1
//           / \
//          2   3
//           \   \
//            5   4
//
// RIGHT VIEW:
//
//   1 3 4
// ======================================================================
int main() {

    // Build binary tree
    Node* root = buildTree();

    vector<int> ans;
    int level = 0;

    // Compute right view
    printRightView(root, ans, level);

    // Print result
    cout << "Right View of Tree:\n";

    for (int val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}