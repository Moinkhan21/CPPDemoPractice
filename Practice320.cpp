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
// LCA in BST
// ===============================
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    // Base case
    if (root == NULL)
        return NULL;

    // Case 1: both nodes lie in left subtree
    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Case 2: both nodes lie in right subtree
    if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Case 3 & 4: split happens OR one equals root
    return root;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5

    LCA of 2 and 8 = 6
    LCA of 2 and 4 = 2
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;              // 2
    TreeNode* q = root->right;             // 8

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->data << " and " << q->data
         << " is: " << lca->data << endl;

    p = root->left;                        // 2
    q = root->left->right;                 // 4
    lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->data << " and " << q->data
         << " is: " << lca->data << endl;

    return 0;
}
