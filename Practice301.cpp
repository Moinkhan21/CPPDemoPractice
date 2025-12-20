#include <iostream>
#include <cmath>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
// Each node contains:
//   • val   → integer value
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with given value
    // and sets left & right children to NULL
    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// GLOBAL FLAG: isbalanced
// ----------------------------------------------------------------------
// Keeps track of whether the tree remains height-balanced.
//
// WHY GLOBAL?
//   • Allows early detection of imbalance during recursion
//   • Avoids unnecessary re-checks once imbalance is found
// ======================================================================
bool isbalanced = true;

// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the height of the binary tree AND checks balance condition
//   simultaneously (optimized O(n) approach).
//
// HEIGHT DEFINITION:
//   Height = number of nodes on the longest path from current node to leaf.
//
// BALANCE CONDITION:
//   For every node:
//       |height(left subtree) - height(right subtree)| ≤ 1
//
// LOGIC:
//   1. Recursively compute left height (lh)
//   2. Recursively compute right height (rh)
//   3. If absolute difference > 1 → tree is NOT balanced
//   4. Return height of current node
//
// TIME COMPLEXITY: O(n)
//   Each node is visited exactly once.
// ======================================================================
int height(TreeNode* root) {
    // Base case: empty tree has height 0
    if (!root) return 0;

    // Recursively calculate heights of left & right subtrees
    int lh = height(root->left);
    int rh = height(root->right);

    // Check balance condition at current node
    if (isbalanced && abs(lh - rh) > 1) {
        isbalanced = false;   // Tree is no longer balanced
    }

    // Return height of current node
    return max(lh, rh) + 1;
}

// ======================================================================
// FUNCTION: isBalanced()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns true if the binary tree is height-balanced, otherwise false.
//
// PROCESS:
//   • Calls height() to compute heights and detect imbalance
//   • Uses global flag `isbalanced` to store result
//
// NOTE:
//   Global flag ensures O(n) time complexity.
// ======================================================================
bool isBalanced(TreeNode* root) {
    height(root);        // Calculate height and update balance status
    return isbalanced;   // Return final balance result
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Constructs a sample binary tree and checks whether it is balanced.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   3
//         /
//        4
//       /
//      5
//
// This tree is NOT height-balanced because left subtree
// height is much larger than right subtree height.
// ======================================================================
int main() {

    // Constructing the binary tree manually
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    // Check if tree is balanced
    if (isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is NOT Balanced\n";

    return 0;
}
