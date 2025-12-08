#include <iostream>
#include <queue>
using namespace std;

// ============================================================================
// CLASS: Node
// ---------------------------------------------------------------------------
// Represents a single node in a binary tree.
// Each node stores:
//     • data  → the value
//     • left  → pointer to left child
//     • right → pointer to right child
// ============================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ============================================================================
// FUNCTION: buildTree()
// ---------------------------------------------------------------------------
// PURPOSE:
//   Build a binary tree recursively using user input.
//   Input is taken in PREORDER: Node → Left → Right
//
// INPUT RULE:
//   Enter -1 when there is no node (NULL).
//
// PROCESS:
//   1. Read data.
//   2. If data == -1 → return NULL.
//   3. Otherwise, create a node.
//   4. Recursively build the left subtree.
//   5. Recursively build the right subtree.
//
// RETURNS:
//   Pointer to the root of the constructed binary tree.
// ============================================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    // BASE CASE: No node here
    if (data == -1) {
        return NULL;
    }

    // Create new node
    Node* root = new Node(data);

    // Recursively construct left subtree
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    // Recursively construct right subtree
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ============================================================================
// FUNCTION: height(Node* root)
// ---------------------------------------------------------------------------
// PURPOSE:
//   Computes the height of a binary tree.
//
// DEFINITION OF HEIGHT:
//   Number of nodes in the longest path from root → leaf.
//   Height of NULL is 0.
//
// RECURSIVE STRATEGY:
//   height = 1 + max(height(left_subtree), height(right_subtree))
//
// TIME COMPLEXITY: O(n)
// ============================================================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// ============================================================================
// FUNCTION: diameterOfBinaryTree()   (O(n²) version)
// ---------------------------------------------------------------------------
// PURPOSE:
//   Computes the diameter of a binary tree.
//
// DIAMETER DEFINITION:
//   Longest path between any two nodes (may or may not pass through root).
//
// THREE POSSIBLE CASES:
//   op1 → diameter in left subtree
//   op2 → diameter in right subtree
//   op3 → height(left) + height(right)  (path passing through root)
//
// FINAL DIAMETER:
//   max(op1, op2, op3)
//
// NOTE:
//   This is an O(n²) solution because height() is called repeatedly.
// ============================================================================
int diameterOfBinaryTree(Node* root) {
    if (root == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left) + height(root->right);

    return max(op1, max(op2, op3));
}

// ============================================================================
// INORDER TRAVERSAL (L → N → R)
// ---------------------------------------------------------------------------
// Visit left subtree → process node → visit right subtree
// ============================================================================
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// ============================================================================
// PREORDER TRAVERSAL (N → L → R)
// ---------------------------------------------------------------------------
// Process node → visit left subtree → visit right subtree
// ============================================================================
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// ============================================================================
// POSTORDER TRAVERSAL (L → R → N)
// ---------------------------------------------------------------------------
// Visit left subtree → visit right subtree → process node
// ============================================================================
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// ============================================================================
// MAIN FUNCTION
// ---------------------------------------------------------------------------
// Builds a tree, performs traversal, computes height and diameter.
// ============================================================================
int main() {
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    cout << "\n\nHeight of Tree = " << height(root);
    cout << "\nDiameter of Tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
