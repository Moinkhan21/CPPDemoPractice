#include <iostream>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// NOTE:
//   In a BST, inorder traversal gives nodes
//   in SORTED (ascending) order.
// ======================================================================
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with given value
    // and sets both children to NULL
    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: KthSmallest()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the Kth smallest element in a BST.
//
// KEY IDEA:
//   • Inorder traversal of BST → sorted order
//   • Traverse nodes in inorder and decrement k
//   • When k becomes 0 → current node is answer
//
// PARAMETERS:
//   • root → current node
//   • k    → reference variable tracking remaining count
//
// WHY PASS k BY REFERENCE?
//   • k must be shared and updated across recursive calls
//
// BASE CASE:
//   • If root is NULL → return -1
//
// TIME COMPLEXITY:
//   O(n) in worst case
//
// SPACE COMPLEXITY:
//   O(h) due to recursion stack
// ======================================================================
int KthSmallest(TreeNode* root, int &k) {

    // Base case: empty subtree
    if (root == NULL) {
        // -1 indicates no answer found in this path
        return -1;
    }

    // --------------------------------------------------
    // Step 1: Traverse LEFT subtree (smaller elements)
    // --------------------------------------------------
    int leftAns = KthSmallest(root->left, k);

    // If answer already found in left subtree, return it
    if (leftAns != -1)
        return leftAns;

    // --------------------------------------------------
    // Step 2: Process CURRENT node
    // --------------------------------------------------
    k--;    // Count this node
    if (k == 0) {
        // Current node is the Kth smallest
        return root->data;
    }

    // --------------------------------------------------
    // Step 3: Traverse RIGHT subtree (larger elements)
    // --------------------------------------------------
    int rightAns = KthSmallest(root->right, k);
    return rightAns;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a sample BST and finds the Kth smallest element.
//
// TREE STRUCTURE:
//
//            5
//           / \
//          3   7
//         / \   \
//        2   4   8
//
// INORDER TRAVERSAL:
//   2 3 4 5 7 8
//
// Example:
//   k = 3 → Kth smallest = 4
// ======================================================================
int main() {

    // Constructing the BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    int k = 3;

    // Find Kth smallest element
    int ans = KthSmallest(root, k);

    cout << "Kth Smallest Element = " << ans << endl;

    return 0;
}
