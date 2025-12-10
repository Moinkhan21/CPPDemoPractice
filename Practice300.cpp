#include <iostream>
using namespace std;

// ===============================
// TreeNode Definition
// ===============================
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

// Global diameter variable
int D = 0;

// ===============================
// FUNCTION: height()
// Returns height of tree and updates diameter
// ===============================
int height(TreeNode* root) {
    if (!root) return 0;

    // Recursively find left and right subtree heights
    int lh = height(root->left);
    int rh = height(root->right);

    // Update global diameter
    D = max(D, lh + rh);

    // Height of current node
    return max(lh, rh) + 1;
}

// ===============================
// FUNCTION: diameterOfBinaryTree()
// ===============================
int diameterOfBinaryTree(TreeNode* root) {
    D = 0;                  // reset global diameter
    height(root);           // compute height & update diameter
    return D;
}

// ===============================
// MAIN FUNCTION (Sample Tree)
// ===============================
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
