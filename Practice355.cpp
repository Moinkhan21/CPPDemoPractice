#include <iostream>
using namespace std;

// =====================================================
// STRUCT: Node
// -----------------------------------------------------
// PURPOSE:
//   Represents a node of a Binary Tree.
//
// DATA MEMBERS:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// NOTE:
//   This tree is NOT necessarily a heap initially.
//   We will validate whether it satisfies heap rules.
// =====================================================
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// =====================================================
// FUNCTION: nodecount
// -----------------------------------------------------
// PURPOSE:
//   Counts the total number of nodes in a binary tree.
//
// WHY NEEDED?
//   • Required to check Complete Binary Tree (CBT)
//   • Helps validate index-based structure
//
// APPROACH:
//   • Recursively count left subtree
//   • Recursively count right subtree
//   • Add 1 for current node
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H) → recursion stack
// =====================================================
int nodecount(Node* root) {
    if (!root)
        return 0;

    int l = nodecount(root->left);
    int r = nodecount(root->right);

    return 1 + l + r;
}

// =====================================================
// FUNCTION: isCBT
// -----------------------------------------------------
// PURPOSE:
//   Checks whether the binary tree is a
//   Complete Binary Tree (CBT).
//
// WHAT IS A CBT?
//   • All levels are completely filled except possibly
//     the last level
//   • Last level nodes are filled from LEFT to RIGHT
//
// METHOD (INDEXING):
//   • Treat tree like array (1-based indexing)
//   • Root at index 1
//   • Left child  → 2*i
//   • Right child → 2*i + 1
//
// RULE:
//   • If any node index exceeds total node count,
//     tree is NOT complete
//
// PARAMETERS:
//   • root → current node
//   • i    → index of current node
//   • n    → total number of nodes
//
// TIME COMPLEXITY: O(N)
// =====================================================
bool isCBT(Node* root, int i, int &n) {

    // Empty tree is complete
    if (!root)
        return true;

    // If index exceeds total nodes → NOT CBT
    if (i > n)
        return false;

    // Check left and right subtrees
    return isCBT(root->left, 2 * i, n) &&
           isCBT(root->right, 2 * i + 1, n);
}

// =====================================================
// FUNCTION: isMaxOrder
// -----------------------------------------------------
// PURPOSE:
//   Checks whether the tree satisfies
//   Max-Heap Order Property.
//
// MAX-HEAP PROPERTY:
//   • Parent value > left child value
//   • Parent value > right child value
//
// CASES:
//   1️⃣ Leaf node → always valid
//   2️⃣ Only left child exists
//   3️⃣ Both children exist
//
// TIME COMPLEXITY: O(N)
// =====================================================
bool isMaxOrder(Node* root) {

    // Empty tree is valid
    if (!root)
        return true;

    // Check left and right subtrees
    bool l = isMaxOrder(root->left);
    bool r = isMaxOrder(root->right);

    bool ans = false;

    // -------------------------------------------------
    // Case 1: Leaf node
    // -------------------------------------------------
    if (!root->left && !root->right) {
        ans = true;
    }

    // -------------------------------------------------
    // Case 2: Only left child exists
    // -------------------------------------------------
    else if (root->left && !root->right) {
        ans = root->data > root->left->data;
    }

    // -------------------------------------------------
    // Case 3: Both children exist
    // -------------------------------------------------
    else {
        ans = root->data > root->left->data &&
              root->data > root->right->data;
    }

    return ans && l && r;
}

// =====================================================
// CLASS: Solution
// -----------------------------------------------------
// PURPOSE:
//   Provides method to check whether a binary tree
//   is a valid Max Heap.
//
// CONDITIONS FOR MAX HEAP:
//   ✔ Tree must be Complete Binary Tree (CBT)
//   ✔ Tree must satisfy Max-Heap Order Property
// =====================================================
class Solution {
public:
    bool isHeap(Node* tree) {

        // Count total nodes
        int n = nodecount(tree);

        // Root index starts from 1
        int i = 1;

        // Tree is heap only if BOTH conditions hold
        return isCBT(tree, i, n) && isMaxOrder(tree);
    }
};

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
            10
           /  \
          9    8
         / \
        7   6

        Properties:
        ✔ Complete Binary Tree
        ✔ Parent > Children

        Hence → Valid Max Heap
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution sol;

    if (sol.isHeap(root))
        cout << "Tree is a Heap" << endl;
    else
        cout << "Tree is NOT a Heap" << endl;

    return 0;
}
