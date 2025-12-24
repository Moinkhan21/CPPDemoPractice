#include <iostream>
#include <climits>
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
// This structure is used to validate whether
// a binary tree is a valid Binary Search Tree (BST).
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with given value
    // and sets both children to NULL
    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: solve()
// ----------------------------------------------------------------------
// PURPOSE:
//   Recursively checks whether the binary tree
//   satisfies BST properties using RANGE validation.
//
// PARAMETERS:
//   • root → current node
//   • lb   → lower bound allowed for current node
//   • ub   → upper bound allowed for current node
//
// BST RULE:
//   • Every node value must lie strictly between
//     its allowed (lb, ub) range.
//
// LOGIC:
//   • If current node is NULL → valid BST
//   • Check if root->val is within (lb, ub)
//   • Recursively validate:
//       - Left subtree with updated upper bound
//       - Right subtree with updated lower bound
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
bool solve(TreeNode* root, long long int lb, long long int ub) {

    // Base case: empty subtree is a valid BST
    if (root == NULL)
        return true;

    // Check if current node satisfies BST range
    if (root->val > lb && root->val < ub) {

        // Validate left subtree
        bool leftAns = solve(root->left, lb, root->val);

        // Validate right subtree
        bool rightAns = solve(root->right, root->val, ub);

        // Tree is valid only if both subtrees are valid
        return leftAns && rightAns;
    }
    else {
        // Current node violates BST property
        return false;
    }
}

// ======================================================================
// FUNCTION: isValidBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Validates whether a given binary tree
//   is a valid Binary Search Tree (BST).
//
// APPROACH:
//   • Uses range-based recursion
//   • Initially sets bounds to (-∞, +∞)
//
// WHY USE LONG LONG?
//   • To safely handle INT_MIN / INT_MAX values
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
bool isValidBST(TreeNode* root) {

    // Initial allowed range for root node
    long long int lowerBound = INT_MIN;
    long long int upperBound = INT_MAX;

    // Call helper function
    bool ans = solve(root, lowerBound, upperBound);

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Creates test cases and checks whether
// each tree is a valid BST.
//
// TEST CASE 1: Valid BST
//
//            5
//           / \
//          3   7
//         / \   \
//        2   4   8
//
// TEST CASE 2: Invalid BST
//
//            5
//           / \
//          3   7
//             /
//            4   ❌ violates BST rule
// ======================================================================
int main() {

    // -------------------------------
    // Test Case 1: Valid BST
    // -------------------------------
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(8);

    cout << "Tree 1 is BST: " << isValidBST(root1) << endl;

    // -------------------------------
    // Test Case 2: Invalid BST
    // -------------------------------
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->right->left = new TreeNode(4); // violates BST rule

    cout << "Tree 2 is BST: " << isValidBST(root2) << endl;

    return 0;
}
