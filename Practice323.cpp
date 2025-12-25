#include <iostream>
#include <vector>
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
//
// This structure is used to solve the
// "Two Sum in a BST" problem.
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
// FUNCTION: storeInorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Stores the inorder traversal of the BST
//   into a vector.
//
// WHY INORDER?
//   • Inorder traversal of a BST gives values
//     in SORTED (ascending) order.
//
// APPROACH:
//   • Left → Node → Right
//   • Push node values into vector
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void storeInorder(TreeNode* root, vector<int> &inorder) {

    // Base case
    if (root == NULL)
        return;

    // Traverse left subtree
    storeInorder(root->left, inorder);

    // Store current node value
    inorder.push_back(root->val);

    // Traverse right subtree
    storeInorder(root->right, inorder);
}

// ======================================================================
// FUNCTION: findTarget()
// ----------------------------------------------------------------------
// PURPOSE:
//   Checks whether there exist TWO DISTINCT nodes
//   in the BST whose sum equals target value k.
//
// APPROACH:
//   1️⃣ Store inorder traversal in a vector (sorted array)
//   2️⃣ Apply TWO-POINTER technique on sorted array
//
// TWO-POINTER LOGIC:
//   • s starts from beginning
//   • e starts from end
//   • If sum == k → return true
//   • If sum > k → move e left
//   • If sum < k → move s right
//
// TIME COMPLEXITY:
//   O(n)
//
// SPACE COMPLEXITY:
//   O(n) (for inorder vector)
// ======================================================================
bool findTarget(TreeNode* root, int k) {

    // Store inorder traversal
    vector<int> inorder;
    storeInorder(root, inorder);

    int s = 0;
    int e = inorder.size() - 1;

    // Two-pointer search
    while (s < e) {
        int sum = inorder[s] + inorder[e];

        if (sum == k)
            return true;
        else if (sum > k)
            e--;
        else
            s++;
    }

    return false;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a sample BST and checks if
// two nodes exist whose sum equals target k.
//
// TREE STRUCTURE:
//
//            5
//           / \
//          3   6
//         / \   \
//        2   4   7
//
// INORDER TRAVERSAL:
//   2 3 4 5 6 7
//
// TARGET:
//   k = 9 → (2 + 7)
// ======================================================================
int main() {

    // Constructing the BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;

    // Check if target sum exists
    cout << "Target exists: " << findTarget(root, k) << endl;

    return 0;
}
