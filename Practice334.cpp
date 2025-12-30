#include <iostream>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • val   → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
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
// FUNCTION: rangeSumBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Calculates the SUM of all node values in a BST
//   that lie within the inclusive range [low, high].
//
// BST PROPERTY USED:
//   • Left subtree  → values smaller than root
//   • Right subtree → values greater than root
//
// OPTIMIZATION (PRUNING):
//   • If root->val < low  → ignore left subtree
//   • If root->val > high → ignore right subtree
//   • If root->val is in range → explore both sides
//
// TIME COMPLEXITY:
//   • Average: O(n)
//   • Best case (balanced tree + pruning): O(log n)
//
// SPACE COMPLEXITY:
//   • O(h) → recursion stack (h = height of tree)
// ======================================================================
int rangeSumBST(TreeNode* root, int low, int high) {

    // Base case: empty subtree
    if (!root) return 0;

    int ans = 0;
    bool wasInRange = false;

    // --------------------------------------------------
    // Step 1: Check if current node lies in range
    // --------------------------------------------------
    if (root->val >= low && root->val <= high) {
        wasInRange = true;
        ans += root->val;   // add current node value
    }

    // --------------------------------------------------
    // Step 2: Decide which subtree(s) to explore
    // --------------------------------------------------

    // Case 1: Current node lies within range
    // → Both subtrees may contain valid values
    if (wasInRange) {
        ans += rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
    // Case 2: Current value is smaller than low
    // → All left subtree values are smaller (ignore them)
    else if (root->val < low) {
        ans += rangeSumBST(root->right, low, high);
    }
    // Case 3: Current value is greater than high
    // → All right subtree values are larger (ignore them)
    else if (root->val > high) {
        ans += rangeSumBST(root->left, low, high);
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST and computes the sum of all node values
// lying within a given range.
//
// TREE STRUCTURE:
//
//            10
//           /  \
//          5    15
//         / \     \
//        3   7     18
//
// RANGE:
//   low = 7, high = 15
//
// VALID NODES:
//   7, 10, 15
//
// RESULT:
//   Sum = 32
// ======================================================================
int main() {

    // Constructing the BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7, high = 15;

    cout << "Range Sum BST = "
         << rangeSumBST(root, low, high) << endl;

    return 0;
}
