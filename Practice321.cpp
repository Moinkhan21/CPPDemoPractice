#include <iostream>
using namespace std;

// ===============================
// TreeNode Definition
// ===============================
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ===============================
// Kth Smallest in BST (Inorder)
// ===============================
int KthSmallest(TreeNode* root, int &k) {

    // Base case
    if (root == NULL) {
        // -1 reflects base condition reached
        return -1;
    }

    // Left subtree
    int leftAns = KthSmallest(root->left, k);
    if (leftAns != -1)
        return leftAns;

    // Current node
    k--;
    if (k == 0) {
        return root->data;
    }

    // Right subtree
    int rightAns = KthSmallest(root->right, k);
    return rightAns;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            5
           / \
          3   7
         / \   \
        2   4   8

    Inorder: 2 3 4 5 7 8
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    int k = 3;
    int ans = KthSmallest(root, k);

    cout << "Kth Smallest Element = " << ans << endl;

    return 0;
}
