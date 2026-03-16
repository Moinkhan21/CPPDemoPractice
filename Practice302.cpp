#include <iostream>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • val   → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// The constructor initializes the node value
// and sets both children to NULL.
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: isSameTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Determines whether two binary trees are IDENTICAL.
//
// DEFINITION OF IDENTICAL TREES:
//
//   Two trees are considered the same if:
//
//   1️⃣ Their root values are equal
//   2️⃣ Their left subtrees are identical
//   3️⃣ Their right subtrees are identical
//
// VISUAL EXAMPLE:
//
//      Tree A            Tree B
//
//        1                 1
//       / \               / \
//      2   3             2   3
//
//   These trees are identical.
//
// RECURSIVE APPROACH:
//
//   For two nodes p and q:
//
//      if both NULL → return true
//      if one NULL  → return false
//      if values differ → return false
//
//      otherwise check:
//          left subtree
//          right subtree
//
// TIME COMPLEXITY: O(N)
//   Each node in the tree is visited once.
//
// SPACE COMPLEXITY: O(H)
//   Recursion stack (H = height of tree)
// ======================================================================
bool isSameTree(TreeNode* p, TreeNode* q) {

    // --------------------------------------------------
    // Case 1: Both nodes are NULL
    // --------------------------------------------------
    // If both trees reached the end simultaneously,
    // they are identical.
    if (!p && !q)
        return true;

    // --------------------------------------------------
    // Case 2: One node is NULL and the other is not
    // --------------------------------------------------
    // Structure mismatch → trees are not identical
    if (!p || !q)
        return false;

    // --------------------------------------------------
    // Case 3: Both nodes exist
    // --------------------------------------------------
    // Check three conditions:
    //
    // 1. Node values must be equal
    // 2. Left subtrees must be identical
    // 3. Right subtrees must be identical
    return (p->val == q->val)
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}


// ======================================================================
// MAIN FUNCTION (Sample Test)
// ----------------------------------------------------------------------
// Builds two binary trees and checks whether they are identical.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   3
//
// EXPECTED OUTPUT:
//   Trees are SAME
// ======================================================================
int main() {

    /* Tree 1
            1
           / \
          2   3
    */
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    /* Tree 2
            1
           / \
          2   3
    */
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Compare both trees
    if (isSameTree(p, q))
        cout << "Trees are SAME\n";
    else
        cout << "Trees are NOT SAME\n";

    return 0;
}