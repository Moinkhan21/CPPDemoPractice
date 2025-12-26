#include <iostream>
#include <vector>
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
// FUNCTION: inorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Stores the INORDER traversal of the BST into a vector.
//
// WHY INORDER?
//   • Inorder traversal of a BST gives nodes
//     in SORTED (ascending) order.
//
// APPROACH:
//   • Left → Node → Right
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void inorder(TreeNode* root, vector<int> &in) {

    // Base case
    if (!root) return;

    // Traverse left subtree
    inorder(root->left, in);

    // Store current node value
    in.push_back(root->val);

    // Traverse right subtree
    inorder(root->right, in);
}

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a HEIGHT-BALANCED BST from a sorted array
//   (inorder traversal).
//
// PARAMETERS:
//   • in    → sorted inorder array
//   • start → starting index
//   • end   → ending index
//
// KEY IDEA:
//   • Choose middle element as root
//   • Left half → left subtree
//   • Right half → right subtree
//
// BASE CASE:
//   • If start > end → return NULL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
TreeNode* buildTree(vector<int> &in, int start, int end) {

    // Base case
    if (start > end) return NULL;

    // Choose middle element
    int mid = (start + end) >> 1;

    // Create root node
    TreeNode* root = new TreeNode(in[mid]);

    // Build left subtree
    root->left = buildTree(in, start, mid - 1);

    // Build right subtree
    root->right = buildTree(in, mid + 1, end);

    return root;
}

// ======================================================================
// FUNCTION: balanceBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts an UNBALANCED BST into a BALANCED BST.
//
// APPROACH:
//   1️⃣ Store inorder traversal of BST (sorted order)
//   2️⃣ Build a balanced BST from the inorder array
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
TreeNode* balanceBST(TreeNode* root) {

    // Store inorder traversal
    vector<int> in;
    inorder(root, in);

    // Build balanced BST from sorted inorder array
    return buildTree(in, 0, in.size() - 1);
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BST level by level (Breadth First Search).
//
// USE CASE:
//   • Used here to verify tree structure
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
// Builds an unbalanced BST, balances it,
// and prints both trees.
//
// UNBALANCED BST:
//
//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//
// BALANCED BST:
//
//                2
//               / \
//              1   3
//                   \
//                    4
// ======================================================================
int main() {

    // Constructing an unbalanced BST
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Original BST (Level Order):\n";
    levelOrderTraversal(root);

    // Balance the BST
    TreeNode* balancedRoot = balanceBST(root);

    cout << "Balanced BST (Level Order):\n";
    levelOrderTraversal(balancedRoot);

    return 0;
}
