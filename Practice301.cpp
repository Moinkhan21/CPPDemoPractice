#include <iostream>
#include <cmath>
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
// GLOBAL VARIABLE: isbalanced
// ----------------------------------------------------------------------
// Keeps track of whether the binary tree remains balanced.
//
// WHY USE A GLOBAL VARIABLE?
//   • Allows detection of imbalance during recursion.
//   • Once an imbalance is found, the flag remains false.
//   • Avoids repeatedly checking conditions in parent calls.
// ======================================================================
bool isbalanced = true;

// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the height of the binary tree while simultaneously
//   checking whether the tree satisfies the height-balanced condition.
//
// HEIGHT DEFINITION:
//   Height = number of nodes on the longest path
//            from the current node to a leaf node.
//
// BALANCED TREE CONDITION:
//   For every node in the tree:
//
//       |height(left subtree) - height(right subtree)| ≤ 1
//
// ALGORITHM:
//
//   1. Recursively compute height of left subtree
//   2. Recursively compute height of right subtree
//   3. Compare the difference of heights
//   4. If difference > 1 → tree is not balanced
//   5. Return height of current node
//
// TIME COMPLEXITY: O(N)
//   Each node is visited exactly once.
//
// SPACE COMPLEXITY: O(H)
//   Recursion stack where H = height of tree.
// ======================================================================
int height(TreeNode* root) {

    // --------------------------------------------------
    // Base Case
    // --------------------------------------------------
    // If node is NULL, height is 0
    if (!root)
        return 0;

    // --------------------------------------------------
    // Recursively calculate height of left subtree
    // --------------------------------------------------
    int lh = height(root->left);

    // --------------------------------------------------
    // Recursively calculate height of right subtree
    // --------------------------------------------------
    int rh = height(root->right);

    // --------------------------------------------------
    // Check balance condition
    // --------------------------------------------------
    // If height difference exceeds 1 → tree not balanced
    if (isbalanced && abs(lh - rh) > 1) {
        isbalanced = false;
    }

    // --------------------------------------------------
    // Return height of current node
    // --------------------------------------------------
    return max(lh, rh) + 1;
}

// ======================================================================
// FUNCTION: isBalanced()
// ----------------------------------------------------------------------
// PURPOSE:
//   Determines whether a binary tree is height-balanced.
//
// PROCESS:
//   • Calls height() to compute subtree heights
//   • height() updates the global flag if imbalance occurs
//   • Returns the final value of the global flag
//
// NOTE:
//   Using this optimized approach avoids recalculating heights
//   multiple times (which would cause O(N²) complexity).
//
// TIME COMPLEXITY: O(N)
// ======================================================================
bool isBalanced(TreeNode* root) {

    // Compute height and detect imbalance
    height(root);

    // Return final balance status
    return isbalanced;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ----------------------------------------------------------------------
// Constructs a binary tree and checks whether it is balanced.
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
// HEIGHT DIFFERENCE:
//
// Left subtree height  = 3
// Right subtree height = 1
//
// Since difference > 1 → tree is NOT balanced.
// ======================================================================
int main() {

    // Construct the binary tree
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