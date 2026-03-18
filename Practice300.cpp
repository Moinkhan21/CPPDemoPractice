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
// GLOBAL VARIABLE: D (Diameter)
// ----------------------------------------------------------------------
// Stores the maximum diameter of the tree.
//
// WHAT IS DIAMETER?
//
//   Diameter of a binary tree is the length of the
//   longest path between any two nodes.
//
//   The path may or may not pass through the root.
//
// WHY GLOBAL?
//
//   • During height calculation, we compute diameter
//   • Avoids recomputation
//   • Keeps solution optimized to O(N)
// ======================================================================
int D = 0;


// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes height of the binary tree AND updates
//   the diameter simultaneously.
//
// HEIGHT DEFINITION:
//
//   Height = number of nodes in the longest path
//            from current node to a leaf.
//
// CORE IDEA:
//
//   For each node:
//
//       diameter_through_node = left_height + right_height
//
//   Update global diameter with maximum value.
//
// ALGORITHM:
//
//   1️⃣ Recursively compute left subtree height (lh)
//   2️⃣ Recursively compute right subtree height (rh)
//   3️⃣ Update diameter: D = max(D, lh + rh)
//   4️⃣ Return height of current node
//
// TIME COMPLEXITY: O(N)
//   Each node is visited once.
//
// SPACE COMPLEXITY: O(H)
//   Recursion stack (H = height of tree)
// ======================================================================
int height(TreeNode* root) {

    // --------------------------------------------------
    // Base Case: Empty node
    // --------------------------------------------------
    if (!root)
        return 0;

    // --------------------------------------------------
    // Compute left subtree height
    // --------------------------------------------------
    int lh = height(root->left);

    // --------------------------------------------------
    // Compute right subtree height
    // --------------------------------------------------
    int rh = height(root->right);

    // --------------------------------------------------
    // Update diameter
    //
    // Longest path passing through current node
    // --------------------------------------------------
    D = max(D, lh + rh);

    // --------------------------------------------------
    // Return height of current node
    // --------------------------------------------------
    return max(lh, rh) + 1;
}


// ======================================================================
// FUNCTION: diameterOfBinaryTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns the diameter of the binary tree.
//
// PROCESS:
//
//   • Reset global diameter
//   • Call height() to compute heights & update diameter
//   • Return final diameter
//
// NOTE:
//
//   Diameter is measured in terms of number of edges
//   (lh + rh).
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H)
// ======================================================================
int diameterOfBinaryTree(TreeNode* root) {

    // Reset global diameter before computation
    D = 0;

    // Compute height and update diameter
    height(root);

    // Return final diameter
    return D;
}


// ======================================================================
// MAIN FUNCTION (Test Case)
// ----------------------------------------------------------------------
// Constructs a binary tree and calculates its diameter.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   3
//         / \
//        4   5
//
// LONGEST PATH:
//
//   4 → 2 → 1 → 3
//
// Number of edges = 3
//
// EXPECTED OUTPUT:
//   Diameter of Binary Tree = 3
// ======================================================================
int main() {

    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate and print diameter
    cout << "Diameter of Binary Tree = "
         << diameterOfBinaryTree(root) << endl;

    return 0;
}