#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
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
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: sum()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts a Binary Tree into a Sum Tree.
//
// WHAT IS A SUM TREE?
//   A Sum Tree is a tree where each node contains the
//   sum of the values of its left and right subtrees
//   in the ORIGINAL tree.
//
//   The value of leaf nodes becomes 0.
//
// EXAMPLE:
//
// Original Tree
//        10
//       /  \
//     -2    6
//    /  \  /  \
//   8  -4 7    5
//
// Sum Tree
//        12
//       /  \
//      4    12
//     / \   / \
//    0   0 0   0
//
// APPROACH:
//   1. Recursively calculate sum of left subtree
//   2. Recursively calculate sum of right subtree
//   3. Replace current node value with (leftSum + rightSum)
//   4. Return total sum of subtree including original node
//
// RETURN VALUE:
//   Returns total sum of ORIGINAL subtree rooted at node.
//
// TIME COMPLEXITY: O(N)
//   Every node is visited exactly once.
//
// SPACE COMPLEXITY: O(H)
//   Recursion stack (H = height of tree)
// ======================================================================
int sum(Node* root) {

    // --------------------------------------------------
    // Base Case: Empty node
    // --------------------------------------------------
    if (!root)
        return 0;

    // --------------------------------------------------
    // Case: Leaf node
    // --------------------------------------------------
    // Leaf nodes become 0 in Sum Tree.
    // But we must return their original value
    // to contribute to parent's sum.
    if (!root->left && !root->right) {

        int temp = root->data; // store original value

        root->data = 0;        // convert leaf to 0

        return temp;           // return original value
    }

    // --------------------------------------------------
    // Recursively compute left and right subtree sums
    // --------------------------------------------------
    int lSum = sum(root->left);
    int rSum = sum(root->right);

    // --------------------------------------------------
    // Store original value of current node
    // --------------------------------------------------
    int temp = root->data;

    // --------------------------------------------------
    // Update current node to sum of children
    // --------------------------------------------------
    root->data = lSum + rSum;

    // --------------------------------------------------
    // Return total sum of subtree
    //
    // subtree sum = original node value + new node value
    // --------------------------------------------------
    return root->data + temp;
}

// ======================================================================
// FUNCTION: toSumtree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Wrapper function to convert a Binary Tree
//   into a Sum Tree.
//
// WHY A WRAPPER?
//   Keeps main logic separate and improves readability.
// ======================================================================
void toSumtree(Node* node) {
    sum(node);
}

// ======================================================================
// FUNCTION: inorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree using Inorder Traversal.
//
// INORDER ORDER:
//   Left → Root → Right
//
// Used here to verify Sum Tree conversion.
// ======================================================================
void inorder(Node* root) {

    if (!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            10
           /  \
          -2   6
         / \   / \
        8  -4 7   5

    After Sum Tree Conversion:

            12
           /  \
          4    12
         / \   / \
        0   0 0   0
    */

    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    // Convert binary tree to Sum Tree
    toSumtree(root);

    // Print the resulting Sum Tree
    cout << "Inorder Traversal of Sum Tree:\n";

    inorder(root);

    cout << endl;

    return 0;
}