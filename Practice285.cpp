#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // ----------------------------------------------------
    // Constructor: initializes a node with given data
    // and sets both children to NULL.
    // ----------------------------------------------------
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// =====================================================================
// FUNCTION: buildTree()
// ---------------------------------------------------------------------
// PURPOSE:
//   Build a binary tree recursively using PREORDER input.
//   PREORDER = Node → Left → Right
//
// INPUT FORMAT:
//   - Enter any integer value for a node
//   - Enter -1 to indicate NULL (no node at this position)
//
// PROCESS:
//   1. Ask user for data.
//   2. If data == -1 → return NULL.
//   3. Create a new node with the given data.
//   4. Recursively build left subtree.
//   5. Recursively build right subtree.
//
// RETURNS:
//   Pointer to the constructed root node.
// =====================================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    // Base case: no node here
    if (data == -1) {
        return NULL;
    }

    // Create new node
    Node* root = new Node(data);

    // Build left subtree
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// =====================================================================
// FUNCTION: height()
// ---------------------------------------------------------------------
// PURPOSE:
//   Computes the height of the binary tree.
//
// HEIGHT DEFINITION:
//   Height = number of nodes on the longest path from root to leaf.
//   • Height of NULL = 0
//   • Height of a leaf node = 1
//
// RECURSIVE FORMULA:
//   height = 1 + max(height(left subtree), height(right subtree))
//
// TIME COMPLEXITY: O(n)
//   Every node is visited exactly once.
// =====================================================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);      // Height of left subtree
    int rightHeight = height(root->right);    // Height of right subtree

    return max(leftHeight, rightHeight) + 1;  // Height of current node
}

// =====================================================================
// FUNCTION: diameterOfBinaryTree()   (O(n²) version)
// ---------------------------------------------------------------------
// PURPOSE:
//   Computes the diameter of the binary tree.
//
// DIAMETER DEFINITION:
//   The diameter is the longest path between ANY two nodes in the tree.
//   This path may or may not pass through the root.
//
// THREE POSSIBLE CASES:
//   op1: Diameter lies entirely in left subtree
//   op2: Diameter lies entirely in right subtree
//   op3: Longest path passes through the root,
//        which is height(left) + height(right)
//
// FINAL RESULT = max(op1, op2, op3)
//
// TIME COMPLEXITY: O(n²)
//   Reason: height() is called inside every recursive call of diameter()
// =====================================================================
int diameterOfBinaryTree(Node* root) {
    if (root == NULL)
        return 0;

    // Option 1: diameter lies in left subtree
    int op1 = diameterOfBinaryTree(root->left);

    // Option 2: diameter lies in right subtree
    int op2 = diameterOfBinaryTree(root->right);

    // Option 3: path that passes through the root
    int op3 = height(root->left) + height(root->right);

    return max(op1, max(op2, op3));
}

// =====================================================================
// MAIN FUNCTION
// ---------------------------------------------------------------------
// Builds a tree using recursive input and prints:
//   1) Height of the tree
//   2) Diameter of the tree
// =====================================================================
int main() {
    Node* root = buildTree();

    cout << "\nHeight of the tree = " << height(root) << endl;
    cout << "Diameter of the tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
