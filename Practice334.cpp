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
// Range Sum BST
// ===============================
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    int ans = 0;
    bool wasInRange = false;

    if (root->val >= low && root->val <= high) {
        wasInRange = true;
        ans += root->val;
    }

    if (wasInRange) {
        ans += rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
    else if (root->val < low) {
        ans += rangeSumBST(root->right, low, high);
    }
    else if (root->val > high) {
        ans += rangeSumBST(root->left, low, high);
    }

    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            10
           /  \
          5    15
         / \     \
        3   7     18

    low = 7, high = 15
    Valid nodes: 7, 10, 15
    Sum = 32
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7, high = 15;

    cout << "Range Sum BST = "
         << rangeSumBST(root, low, high) << endl;

    return 0;
}
