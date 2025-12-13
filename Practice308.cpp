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

// Global answer counter
int ans = 0;

// ===============================
// Count paths starting from ONE root
// ===============================
void pathFromOneRoot(TreeNode* root, long long sum) {
    if (!root) return;

    if (sum == root->val) {
        ++ans;
    }

    pathFromOneRoot(root->left, sum - root->val);
    pathFromOneRoot(root->right, sum - root->val);
}

// ===============================
// Count paths starting from ALL nodes
// ===============================
int pathSum(TreeNode* root, long long targetSum) {
    if (root) {
        pathFromOneRoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
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
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2   1

    Target Sum = 8
    Valid paths:
      5 → 3
      5 → 2 → 1
      -3 → 11
    Answer = 3
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    ans = 0;  // IMPORTANT: reset before calling
    cout << "Number of paths = " << pathSum(root, 8) << endl;

    return 0;
}
