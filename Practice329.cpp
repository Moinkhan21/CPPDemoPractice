#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • val   → value stored in the node
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
// FUNCTION: build()
// ----------------------------------------------------------------------
// PURPOSE:
//   Recursively builds a BST from preorder traversal
//   using RANGE (min, max) constraints.
//
// PARAMETERS:
//   • i        → current index in preorder array (passed by reference)
//   • min      → lower bound allowed for current node
//   • max      → upper bound allowed for current node
//   • preorder → preorder traversal array
//
// KEY IDEA:
//   • Preorder order: Root → Left → Right
//   • Maintain valid value range for each subtree
//   • Move index forward only when node is created
//
// BASE CASES:
//   • If index exceeds array size → return NULL
//   • If current value not in (min, max) → return NULL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
TreeNode* build(int &i, int min, int max, vector<int> &preorder) {

    // If all elements are processed
    if (i >= preorder.size()) {
        return nullptr;
    }

    TreeNode* root = nullptr;

    // Check if current value lies within valid BST range
    if (preorder[i] > min && preorder[i] < max) {

        // Create node with current preorder value
        root = new TreeNode(preorder[i++]);

        // Build left subtree with updated upper bound
        root->left = build(i, min, root->val, preorder);

        // Build right subtree with updated lower bound
        root->right = build(i, root->val, max, preorder);
    }

    return root;
}

// ======================================================================
// FUNCTION: bstFromPreorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a BST from its preorder traversal.
//
// APPROACH:
//   • Uses helper function with range constraints
//   • Initializes bounds as (-∞, +∞)
//   • Starts index from 0
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
TreeNode* bstFromPreorder(vector<int> &preorder) {

    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    return build(i, min, max, preorder);
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BST level by level (Breadth First Search).
//
// USE CASE:
//   • Verifies correct structure of constructed BST
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST from preorder traversal
// and prints it using level order traversal.
//
// PREORDER INPUT:
//   [8, 5, 1, 7, 10, 12]
//
// CONSTRUCTED BST:
//
//                8
//               / \
//              5   10
//             / \    \
//            1   7    12
// ======================================================================
int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Construct BST from preorder traversal
    TreeNode* root = bstFromPreorder(preorder);

    // Verify BST structure
    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);

    return 0;
}
