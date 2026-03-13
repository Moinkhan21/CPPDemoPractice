#include <iostream>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • val   → value stored in the node
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
// GLOBAL VARIABLE
// ----------------------------------------------------------------------
// ans → stores the total number of valid paths
//       whose sum equals the target.
//
// We keep it global so that recursive calls
// can update the same counter.
// ======================================================================
int ans = 0;

// ======================================================================
// FUNCTION: pathFromOneRoot()
// ----------------------------------------------------------------------
// PURPOSE:
//   Counts the number of paths that START from the
//   current node and whose sum equals the target.
//
// PARAMETERS:
//   • root → current node
//   • sum  → remaining sum needed to reach target
//
// APPROACH:
//   1. If current node value equals remaining sum
//      → we found a valid path.
//   2. Reduce the remaining sum by current node value.
//   3. Continue exploring left and right subtree.
//
// IMPORTANT:
//   This function ONLY considers paths starting
//   from ONE specific node.
//
// TIME COMPLEXITY: O(N) in worst case for each call
// SPACE COMPLEXITY: O(H) recursion stack
// ======================================================================
void pathFromOneRoot(TreeNode* root, long long sum) {

    // Base Case
    // If node is NULL, stop recursion
    if (!root)
        return;

    // --------------------------------------------------
    // Check if current node completes the required sum
    // --------------------------------------------------
    if (sum == root->val) {
        ++ans;
    }

    // --------------------------------------------------
    // Continue searching in left subtree
    // Reduce remaining sum
    // --------------------------------------------------
    pathFromOneRoot(root->left, sum - root->val);

    // --------------------------------------------------
    // Continue searching in right subtree
    // --------------------------------------------------
    pathFromOneRoot(root->right, sum - root->val);
}

// ======================================================================
// FUNCTION: pathSum()
// ----------------------------------------------------------------------
// PURPOSE:
//   Counts total number of paths whose sum equals
//   the target sum.
//
// IMPORTANT CONDITION:
//   Paths can start from ANY node in the tree,
//   but must move DOWNWARD.
//
// APPROACH:
//   For every node:
//     1. Treat that node as a starting point
//     2. Count valid paths starting from it
//     3. Recursively check the same for left subtree
//     4. Recursively check the same for right subtree
//
// TIME COMPLEXITY: O(N²) in worst case
//   (for skewed tree)
//
// SPACE COMPLEXITY: O(H)
//   where H = height of tree
// ======================================================================
int pathSum(TreeNode* root, long long targetSum) {

    // If node exists
    if (root) {

        // --------------------------------------------------
        // Count paths starting from THIS node
        // --------------------------------------------------
        pathFromOneRoot(root, targetSum);

        // --------------------------------------------------
        // Explore left subtree as new starting points
        // --------------------------------------------------
        pathSum(root->left, targetSum);

        // --------------------------------------------------
        // Explore right subtree as new starting points
        // --------------------------------------------------
        pathSum(root->right, targetSum);
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            10
           /  \
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2   1

    Target Sum = 8

    Valid Paths:
      5 → 3
      5 → 2 → 1
      -3 → 11

    Total Paths = 3
    */

    // Creating the binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    // Reset global counter before calling function
    ans = 0;

    cout << "Number of paths = "
         << pathSum(root, 8) << endl;

    return 0;
}