#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • data  → integer value stored in the node
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
//   Builds a binary tree using recursion and user input.
//
// INPUT RULE:
//   • Enter -1 → represents NULL (no node)
//
// TREE CREATION:
//   Root → Left subtree → Right subtree
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
// FUNCTION: printLeftBoundary()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the LEFT boundary of the tree (excluding leaf nodes).
//
// RULES:
//   • Traverse top-down
//   • Skip leaf nodes
//   • Prefer left child, else go right
//
// EXAMPLE:
//   1 → 2 → 4
// ======================================================================
void printLeftBoundary(Node* root) {

    // Base Case
    if (root == NULL)
        return;

    // Skip leaf nodes
    if (root->left == NULL && root->right == NULL)
        return;

    // Print current node
    cout << root->data << " ";

    // Move to next boundary node
    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

// ======================================================================
// FUNCTION: printLeafBoundary()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints all LEAF nodes (left to right).
//
// RULE:
//   Node with no left and right child is a leaf.
//
// EXAMPLE:
//   Leaves → 4, 5, 6
// ======================================================================
void printLeafBoundary(Node* root) {

    if (root == NULL)
        return;

    // If leaf node, print it
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }

    // Traverse left and right subtree
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

// ======================================================================
// FUNCTION: printRightBoundary()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the RIGHT boundary of the tree (excluding leaves).
//
// RULES:
//   • Traverse bottom-up
//   • Skip leaf nodes
//   • Prefer right child, else go left
//
// IMPORTANT:
//   Printing is done AFTER recursion to reverse order.
//
// EXAMPLE:
//   3 → 6 → 9 (printed bottom-up)
// ======================================================================
void printRightBoundary(Node* root) {

    // Base Case
    if (root == NULL)
        return;

    // Skip leaf nodes
    if (root->left == NULL && root->right == NULL)
        return;

    // Move first (reverse order printing)
    if (root->right)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);

    // Print after recursion
    cout << root->data << " ";
}

// ======================================================================
// FUNCTION: boundaryTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs BOUNDARY TRAVERSAL of a Binary Tree.
//
// WHAT IS BOUNDARY TRAVERSAL?
//
//   Traversal in anti-clockwise direction:
//
//       1. Root
//       2. Left Boundary (excluding leaves)
//       3. Leaf Nodes
//       4. Right Boundary (excluding leaves, bottom-up)
//
// VISUAL EXAMPLE:
//
//            1
//          /   \
//         2     3
//        / \     \
//       4   5     6
//
// Boundary Traversal:
//   1 → 2 → 4 → 5 → 6 → 3
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H)
// ======================================================================
void boundaryTraversal(Node* root) {

    if (root == NULL)
        return;

    // Step 1: Print root
    cout << root->data << " ";

    // Step 2: Left boundary
    printLeftBoundary(root->left);

    // Step 3: Leaf nodes
    printLeafBoundary(root);

    // Step 4: Right boundary
    printRightBoundary(root->right);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a binary tree and prints its boundary traversal.
//
// INPUT EXAMPLE:
//   1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
//
// OUTPUT:
//   Boundary Traversal of Tree
// ======================================================================
int main() {

    // Build tree from user input
    Node* root = buildTree();

    cout << "Boundary Traversal: ";

    // Perform boundary traversal
    boundaryTraversal(root);

    return 0;
}