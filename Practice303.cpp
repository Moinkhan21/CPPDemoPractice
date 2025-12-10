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

// ===============================
// FUNCTION: isMirror()
// Checks if two trees are mirror images
// ===============================
bool isMirror(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;

    if (p && q) {
        return (p->val == q->val)
            && isMirror(p->left, q->right)
            && isMirror(p->right, q->left);
    }

    return false; // one NULL, one not → not mirror
}

// ===============================
// FUNCTION: isSymmetric()
// A tree is symmetric if left & right subtrees are mirror
// ===============================
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// ===============================
// MAIN FUNCTION (Example Test)
// ===============================
int main() {

    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric\n";
    else
        cout << "Tree is NOT Symmetric\n";

    return 0;
}
