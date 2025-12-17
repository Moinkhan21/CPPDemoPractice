#include <iostream>
#include <vector>
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
// Store Inorder Traversal
// ===============================
void storeInorder(TreeNode* root, vector<int> &inorder) {
    if (root == NULL)
        return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->val);
    storeInorder(root->right, inorder);
}

// ===============================
// Find Target Sum in BST
// ===============================
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    storeInorder(root, inorder);

    int s = 0;
    int e = inorder.size() - 1;

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

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            5
           / \
          3   6
         / \   \
        2   4   7

    Inorder: 2 3 4 5 6 7
    Target = 9 → (2 + 7)
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;

    cout << "Target exists: " << findTarget(root, k) << endl;

    return 0;
}
