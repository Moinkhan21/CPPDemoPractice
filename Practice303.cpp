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
// FUNCTION: isMirror()
// ----------------------------------------------------------------------
// PURPOSE:
//   Determines whether two binary trees are mirror images
//   of each other.
//
// WHAT IS A MIRROR TREE?
//
//   Two trees are mirrors if:
//
//   1️⃣ Their root values are equal
//   2️⃣ Left subtree of one tree is mirror of right subtree of the other
//   3️⃣ Right subtree of one tree is mirror of left subtree of the other
//
// VISUAL EXAMPLE:
//
//      Tree A            Tree B
//        2                 2
//       / \               / \
//      3   4             4   3
//
// RECURSIVE RULE:
//
//    Mirror(p, q) is true if:
//
//        p->val == q->val
//        AND
//        Mirror(p->left, q->right)
//        AND
//        Mirror(p->right, q->left)
//
// BASE CASES:
//
//   • If both nodes are NULL → true
//   • If only one is NULL → false
//
// TIME COMPLEXITY: O(N)
//   Every node is visited once.
//
// SPACE COMPLEXITY: O(H)
//   Recursion stack (H = height of tree)
// ======================================================================
bool isMirror(TreeNode* p, TreeNode* q) {

    // --------------------------------------------------
    // Case 1: Both nodes are NULL
    // --------------------------------------------------
    // Two empty trees are mirrors of each other
    if (!p && !q)
        return true;

    // --------------------------------------------------
    // Case 2: Both nodes exist
    // --------------------------------------------------
    if (p && q) {

        return (p->val == q->val)           // Values must match
            && isMirror(p->left, q->right) // Left subtree vs Right subtree
            && isMirror(p->right, q->left);// Right subtree vs Left subtree
    }

    // --------------------------------------------------
    // Case 3: One node is NULL and the other is not
    // --------------------------------------------------
    // Trees cannot be mirrors
    return false;
}

// ======================================================================
// FUNCTION: isSymmetric()
// ----------------------------------------------------------------------
// PURPOSE:
//   Determines whether a binary tree is symmetric
//   around its center.
//
// WHAT IS A SYMMETRIC TREE?
//
//   A tree is symmetric if its left and right
//   subtrees are mirror images of each other.
//
// EXAMPLE:
//
//            1
//           / \
//          2   2
//         / \ / \
//        3  4 4  3
//
// Left subtree mirrors the right subtree.
//
// APPROACH:
//
//   Simply check:
//
//       isMirror(root->left, root->right)
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H)
// ======================================================================
bool isSymmetric(TreeNode* root) {

    // Empty tree is symmetric
    if (!root)
        return true;

    // Check if left and right subtrees are mirrors
    return isMirror(root->left, root->right);
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ----------------------------------------------------------------------
// Constructs a symmetric binary tree and checks whether
// the tree is symmetric.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   2
//         / \ / \
//        3  4 4  3
//
// EXPECTED OUTPUT:
//   Tree is Symmetric
// ======================================================================
int main() {

    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Check symmetry
    if (isSymmetric(root))
        cout << "Tree is Symmetric\n";
    else
        cout << "Tree is NOT Symmetric\n";

    return 0;
}