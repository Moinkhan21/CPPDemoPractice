#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// PURPOSE:
//   Node class represents a single element of the Binary Tree.
//
// DATA MEMBERS:
//   • data  → integer value stored in this node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// CONSTRUCTOR:
//   Initializes node with given value and sets children to NULL.
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        // Assign the passed value to current node
        this->data = data;

        // Initially no children are attached
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds binary tree RECURSIVELY from user input.
//
// INPUT CONVENTION:
//   • User enters node value in PREORDER fashion
//   • Value = -1 means → this position is NULL
//
// STEPS:
//   1️⃣ Read data
//   2️⃣ If -1 → return NULL
//   3️⃣ Create node
//   4️⃣ Build LEFT child
//   5️⃣ Build RIGHT child
//
// TIME COMPLEXITY: O(n)
//   Each node created exactly once
// SPACE COMPLEXITY: O(h)
//   Due to recursion call stack
// ======================================================================
Node* buildTree() {

    int data;

    // Ask user for data
    cout << "Enter data: ";

    // Read data from console
    cin >> data;

    // -------------------------------
    // BASE CASE
    // -------------------------------
    if (data == -1)
        return NULL;

    // -------------------------------
    // CREATE CURRENT NODE
    // -------------------------------
    Node* root = new Node(data);

    // Build LEFT subtree
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    // Build RIGHT subtree
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    // Return root of constructed tree
    return root;
}

// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   Calculates HEIGHT of Binary Tree recursively.
//
// HEIGHT DEFINITION:
//   • Number of nodes in longest path from
//     this node → leaf node.
//
// APPROACH:
//   1️⃣ Find height of left subtree
//   2️⃣ Find height of right subtree
//   3️⃣ Height = 1 + max(left, right)
//
// RETURN:
//   • Height of tree rooted at 'root'
//
// TIME COMPLEXITY: O(n)
// ======================================================================
int height(Node* root) {

    // -------------------------------
    // BASE CASE
    // -------------------------------
    if (root == NULL)
        return 0;

    // -------------------------------
    // RECURSIVE CALLS
    // -------------------------------

    // Get height from LEFT child
    int leftHeight = height(root->left);

    // Get height from RIGHT child
    int rightHeight = height(root->right);

    // Return final height
    return 1 + max(leftHeight, rightHeight);
}

// ======================================================================
// FUNCTION: isBalanced()
// ----------------------------------------------------------------------
// PURPOSE:
//   Checks whether Binary Tree is HEIGHT-BALANCED.
//
// BALANCED TREE CONDITION:
//   • For every node:
//       | height(left) – height(right) | ≤ 1
//
// STEPS:
//   1️⃣ Compute left height
//   2️⃣ Compute right height
//   3️⃣ Check difference condition
//   4️⃣ Recursively check left subtree
//   5️⃣ Recursively check right subtree
//
// TIME COMPLEXITY: O(n²)
//   Because for each node we are again calling
//   height() which is O(n).
//
// SPACE COMPLEXITY: O(h)
// ======================================================================
bool isBalanced(Node* root) {

    // -------------------------------
    // BASE CASE
    // -------------------------------
    if (root == NULL)
        return true;

    // -------------------------------
    // STEP 1: FIND HEIGHTS
    // -------------------------------
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // -------------------------------
    // STEP 2: CHECK DIFFERENCE
    // -------------------------------
    int diff = abs(leftHeight - rightHeight);

    // Condition for current node
    bool currInRange = (diff <= 1);

    // -------------------------------
    // STEP 3: RECUR DOWN
    // -------------------------------
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    // Final answer depends on all 3
    return (currInRange && leftAns && rightAns);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// PURPOSE:
//   • Build tree
//   • Print height
//   • Validate if balanced
//
// FLOW:
//   1️⃣ buildTree()
//   2️⃣ height()
//   3️⃣ isBalanced()
// ======================================================================
int main() {

    // Initially tree root is empty
    Node* root = buildTree();

    // Print HEIGHT of whole tree
    cout << "\nHeight of Tree: "
         << height(root) << endl;

    // Check BALANCED condition
    if (isBalanced(root))
        cout << "The tree is Balanced" << endl;
    else
        cout << "The tree is NOT Balanced" << endl;

    return 0;
}
